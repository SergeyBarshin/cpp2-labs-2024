#include <cstring>
#include "Planet.hpp"
#include <iostream>
//Конструктор по умолчанию

namespace planet {
    Planet::Planet(){
        name = new char[1];
        name[0] = '\0';
        //std::strcpy(name, "NULL");
        diamiter = 0;
        life = 0;
        satelites = 0;
    }

    //Конструктор с параметрами
    Planet::Planet(const char* newName, int newdiamiter, int newlife, int newsatelites){
        name = new char[strlen(newName)+1];
        strcpy(name, newName);
        diamiter = newdiamiter;
        life = newlife;
        satelites = newsatelites;
    }

    Planet::Planet(const Planet &p){
        //delete[] name;
        name = new char[strlen(p.name)+1];
        std::strcpy(name, p.name);
        //name = p.name;
        diamiter = p.diamiter;
        life = p.life;
        satelites = p.satelites;
    }
        
    //Planet::Planet(const Planet &p) = delete;   // удаляем конструктор
    //Деструктор
    Planet::~Planet() {
       delete[] name; // из-за этого все и сломалось
    }

    // ф-ции получения значений
    char* Planet::getName() {
        return name;
    }
    int Planet::getDiamiter() {
        return diamiter;
    }
    int Planet::getLife() {
        return life;
    }
    int Planet::getSatelites() {
        return satelites;
    }

    // ф-ции возврата значений
    void Planet::setName(const char* newName) {
        delete[] name;
        name = new char[strlen(newName)+1];
        std::strcpy(name, newName);
    }
    void Planet::setDiamiter(int newDiamiter) {
        diamiter = newDiamiter;
    }
    void Planet::setLife(int newLife) {
        life = newLife;
    }
    void Planet::setSatelites(int newSatelites) {
        satelites = newSatelites;
    }

    std::ostream & operator << (std::ostream &out, const Planet& planet){
        out << planet.name << ' ' << planet.diamiter << ' ' << planet.life << ' ' << planet.satelites << std::endl;
        //out << "перреререррере\n";
        return out;
    }

    std::istream & operator >> (std::istream &in,  Planet& planet){
        char tmp[40];
        in >> tmp;
        planet.name = new char[strlen(tmp)+1];
        std::strcpy(planet.name, tmp);

        in >> planet.diamiter;
        in >> planet.life;
        in >> planet.satelites;
        return in;
    }

    bool operator < (const Planet& planet1, const Planet& planet2){
        return strcmp(planet1.name, planet2.name) < 0;
    }
    bool operator > (const Planet& planet1, const Planet& planet2){
        return strcmp(planet1.name, planet2.name) > 0;
    }
    bool operator== (const Planet& planet1, const Planet& planet2){
        return strcmp(planet1.name, planet2.name) == 0;
    }

    Planet& Planet::operator=(const Planet& p2) { 
        if (this != &p2){
            delete[] this->name;
            this->name = new char[strlen(p2.name)+1];
            strcpy(this->name, p2.name);
            this->diamiter = p2.diamiter; 
            this->life = p2.life; 
            this->satelites = p2.satelites; 
        }
        return *this;
    } 

    // опертор присваивания
    // конструктор копирования
    int getPlanet(Planet* arr, int& curSize, const char* targetName)
    {
        for (int i = 0; i < curSize; i++){
            if (strcmp(arr[i].getName(), targetName) == 0){
                return i;
            }
        }
        return -1;
    }

    void addObjToDB(Planet* arr, int maxSize, int& curSize, const char* name, int diamiter, int life, int satelites){
        if (curSize >= maxSize || getPlanet(arr, curSize, name) != -1){
            std::cout << "База данных заполенена или такая планета уже существует\n";
            return;
        }
        arr[curSize] = Planet(name, diamiter, life, satelites);
        curSize += 1;
    }

    void printDb(Planet* arr, int n){
        std::cout << "   Название    | Диаметр | Жизнь | Спутники |\n";
        std::cout << "---------------|---------|-------|----------|\n";
        for(int i = 0; i < n; i++){
            std::cout << i + 1 << ". " << arr[i].getName() << std::setw(15 - strlen(arr[i].getName()) + 6)
            << arr[i].getDiamiter() << std::setw(8) << arr[i].getLife() 
            << std::setw(11) << arr[i].getSatelites() <<std::endl;
        }
        std::cout << '\n';
    }


    void updateDb(Planet* arr, int& curSize, const char* targetName, const char* name = "", int diamiter = -1, int life = -1, int satelites = -1){
        int targetId = getPlanet(arr, curSize, targetName);
        if (targetId == -1){
            std::cout << "Планета не найдена\n";
            return;
        }

        if (strcmp(name, "") != 0) { arr[targetId].setName(name); }
        if (diamiter != -1) { arr[targetId].setDiamiter(diamiter); }
        if (life != -1) { arr[targetId].setLife(life); }
        if (satelites != -1) { arr[targetId].setSatelites(satelites); }
    }


    void deleteByName(Planet* arr, int& curSize, const char* targetName){
        int targetId = getPlanet(arr, curSize, targetName);
        if (targetId == -1){
            std::cout << "Планета не найдена!\n";
            return;
        }

        for (int i = targetId; i < curSize; i++)
            arr[i] = arr[i+1];
        curSize--;
    }


    void sortByName(Planet* arr, int curSize){
        for (int i = 0; i < curSize; i++){
            for (int j = i + 1; j < curSize; j++){
                if (arr[i] > arr[j])
                    std::swap(arr[i], arr[j]);
            }
        }

    }


    int readDbFromFile(const char *filename, Planet *arr, int &n) {
        std::ifstream fin(filename, std::ios::in);
        if (!fin) {
            std::cout << "Heт файла " << filename << std::endl;
            return 1;
        }
        fin >> n;
        if (n > 100) {
            std::cout << "Переполнение БД. n= " << n << std::endl;
            return 1;
        }

        for (int i = 0; i < n; i++){
            fin >> arr[i];
        }

        fin.close();
        return 0;
    }


    void writeDbToFile(const char *filename, Planet* arr, int n){
        std::ofstream fout;
        fout.open(filename, std::ios::binary);

        if (!fout) {
            std::cout << "Ошибка открытия файла" << std::endl;
            return ;
        }
        fout << n;
        for (int i = 0; i < n; i++)
            //fout << arr[i].getName() << ' ' << arr[i].getDiamiter() << ' ' << arr[i].getLife() << ' ' << arr[i].getSatelites() << std::endl;
            fout << arr[i];
        fout.close();
    }

}