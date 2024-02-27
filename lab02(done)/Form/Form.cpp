#include <cstring>
#include "Form.hpp"
#include <iostream>
//Конструктор по умолчанию
namespace form {

    Form::Form(){
        name = new char[1];
        //std::strcpy(name, "NULL");
        name[0] = '\0';
        bus = 0;
        subway = 0;
        tram = 0;
    }

    //Конструктор с параметрами
    Form::Form(const char* newName, int newbus, int newsubway, int newtram) {
        name = new char[strlen(newName)+1];
        std::strcpy(name, newName);
        bus = newbus;
        subway = newsubway;
        tram = newtram;
    }

    Form::Form(const Form &p){
        //delete[] name;
        name = new char[strlen(p.name)+1];
        std::strcpy(name, p.name);
        //name = p.name;
        bus = p.bus;
        subway = p.subway;
        tram = p.tram;
    }

    //Деструктор
    Form::~Form() {
        delete[] name;
    }

    // ф-ции получения значений
    char* Form::getName() {
        return name;
    }
    int Form::getBus() {
        return bus;
    }
    int Form::getSubway() {
        return subway;
    }
    int Form::getTram() {
        return tram;
    }

    // ф-ции возврата значений
    void Form::setName(const char* newName) {
        delete[] name;
        name = new char[strlen(newName)];
        std::strcpy(name, newName);
    }
    void Form::setBus(int newBus) {
        bus = newBus;
    }
    void Form::setSubway(int newSubway) {
        subway = newSubway;
    }
    void Form::setTram(int newTram) {
        tram = newTram;
    }

    std::ostream & operator << (std::ostream &out, const Form& Form){
        out << Form.name << ' ' << Form.bus << ' ' << Form.subway << ' ' << Form.tram << std::endl;
        //out << "перреререррере\n";
        return out;
    }

    std::istream & operator >> (std::istream &in,  Form& Form){
        char tmp[80];
        in >> tmp;
        Form.name = new char[strlen(tmp)+1];
        std::strcpy(Form.name, tmp);

        in >> Form.bus;
        in >> Form.subway;
        in >> Form.tram;
        return in;
    }

    bool operator < (const Form& Form1, const Form& Form2){
        return strcmp(Form1.name, Form2.name) < 0;
    }
    bool operator > (const Form& Form1, const Form& Form2){
        return strcmp(Form1.name, Form2.name) > 0;
    }
    bool operator== (const Form& Form1, const Form& Form2){
        return strcmp(Form1.name, Form2.name) == 0;
    }

    Form& Form::operator=(const Form& p2) { 
        if (this != &p2){
            delete[] this->name;
            this->name = new char[strlen(p2.name)+1];
            strcpy(this->name, p2.name);
            this->bus = p2.bus; 
            this->subway = p2.subway; 
            this->tram = p2.tram; 
        }
        return *this;
    } 

    int getForm(Form* arr, int& curSize, const char* targetName){
        for (int i = 0; i < curSize; i++){
            if (strcmp(arr[i].getName(), targetName) == 0){
                return i;
            }
        }
        return -1;
    }

    void addObjToDB(Form* arr, int maxSize, int& curSize) {
        Form tmp;
        std::cout << "Введите: имя, оценку автобуса, оценку метро, оценку трамвая\n";
        std::cin >> tmp;
        if (curSize >= maxSize){
            std::cout << "База данных заполенена или такая планета уже существует\n";
            return;
        }
        //arr[curSize] = Form(name, bus, subway, tram);
        arr[curSize] = tmp;
        curSize += 1;
    }

    void printDb(Form* arr, int n){
        std::cout << "   Имя/фамилия    | Автобуc | Метро | Трамвай |\n";
        std::cout << "------------------|---------|-------|---------|\n";
        for(int i = 0; i < n; i++){
            std::cout << i + 1 << ". " << arr[i].getName() << std::setw(18 - strlen(arr[i].getName()) + 6)
            << arr[i].getBus() << std::setw(8) << arr[i].getSubway() 
            << std::setw(11) << arr[i].getTram() <<std::endl;
        }
        std::cout << '\n';
    }


    void updateDb(Form* arr, int& curSize){
        char targetName[80];
        std::cout << "Введите имя респондента\n";
        std::cin >> targetName;

        
        int targetId = getForm(arr, curSize, targetName);
        if (targetId == -1){
            std::cout << "Респондент не найден\n";
            return;
        }

        char name[80];
        int bus;
        int subway;
        int tram;

        std::cout << "Введите новое имя (-1 чтобы пропустить): ";
        std::cin >> name;
        std::cout << "Введите кол-во автобусов (-1 чтобы пропустить): ";
        std::cin >> bus;
        std::cout << "Введите кол-во метро (-1 чтобы пропустить): ";
        std::cin >> subway;
        std::cout << "Введите кол-во трамваев (-1 чтобы пропустить): ";
        std::cin >> tram;

        if (strcmp(name, "-1") != 0) { arr[targetId].setName(name); }
        if (bus != -1) { arr[targetId].setBus(bus); }
        if (subway != -1) { arr[targetId].setSubway(subway); }
        if (tram != -1) { arr[targetId].setTram(tram); }
    }


    void deleteByName(Form* arr, int& curSize){
        std::cout << "Введите имя фамилию, которую хотите удалить\n";
        char tmp[80];
        std::cin >> tmp;
        int targetId = getForm(arr, curSize, tmp);
        if (targetId == -1){
            std::cout << "Респондент не найден!\n";
            return;
        }

        for (int i = targetId; i < curSize; i++)
            arr[i] = arr[i+1];
        curSize--;
    }


    void sortByName(Form* arr, int curSize){
        for (int i = 0; i < curSize; i++){
            for (int j = i + 1; j < curSize; j++){
                if (arr[i] > arr[j])
                    std::swap(arr[i], arr[j]);
            }
        }

    }


    int readDbFromFile(const char *filename, Form *arr, int &n) {
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


    void writeDbToFile(const char *filename, Form* arr, int n) {
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