#include <iostream>
#include <fstream>
#include "Planet/Planet.hpp"
#include "Form/Form.hpp"


int menu() {
    std::cout << " ============== ГЛАВНОЕ МЕНЮ ========================\n";
    std::cout << "1 - чтение БД из файла\t\t 4 - добавление нового объекта в БД" << std::endl;
    std::cout << "2 - запись БД в файл\t\t 5 - удаление объекта из БД" << std::endl;
    std::cout << "3 - сортировка БД\t\t 6 - редактирование БД" << std::endl;
    std::cout << "7 - вывод БД на экран\t\t 8 - выход" << std::endl;
    std::cout << "Для выбора операции введите цифру от 1 до 8:" << std::endl;
    int resp;
    std::cin >> resp;
    std::cin.clear();
    std::cin.ignore(10, '\n');
    return resp;
}

int main() {
    const int maxDbSize = 100;
    int curDbSize = 0;
    Planet* planetsArray = new Planet[maxDbSize];
    std::cout << "----------Считано из файла----------\n";
    Planet::readDbFromFile("sourcePlanet.txt", planetsArray, curDbSize);
    Planet::printDb(planetsArray, curDbSize);

    std::cout << "----------Добавили венеру----------\n";
    Planet::addObjToDB(planetsArray, maxDbSize, curDbSize, "Venus", 12103, 0, 0);
    Planet::printDb(planetsArray, curDbSize);

    std::cout << "----------Удалили землю----------\n";
    Planet::deleteByName(planetsArray, curDbSize, "Earth");
    Planet::printDb(planetsArray, curDbSize);

    std::cout << "----------Добавили землю 2----------\n";
    Planet::addObjToDB(planetsArray, maxDbSize, curDbSize,"Earth2", 12742*2, 1, 1*2);
    Planet::printDb(planetsArray, curDbSize);

    std::cout << "----------Отредактировали марс----------\n";
    Planet::updateDb(planetsArray, curDbSize, "Mars", "Mars_updated", 10, 1, -1);
    Planet::printDb(planetsArray, curDbSize);

    std::cout << "----------Отсортировали БД----------\n";
    Planet::sortByName(planetsArray, curDbSize);
    Planet::printDb(planetsArray, curDbSize);
    

    Planet::writeDbToFile("resultPlanet.txt", planetsArray, curDbSize);
    
    std::cout << "\n\nИнтерактивное взаимодействие с классом 'анкета для опроса населения'\n\n";

    const int maxDbSizeForm = 100;
    int curDbSizeForm = 0;
    Form* formArray = new Form[maxDbSize];

    while (true) {
        switch (menu()) {
            case 1: 
                Form::readDbFromFile("sourceForm.txt", formArray, curDbSizeForm);
                break; 
            case 2: 
                Form::writeDbToFile("resultForm.txt", formArray, curDbSizeForm);
                break;
            case 3:
                Form::sortByName(formArray, curDbSizeForm);
                break;
            case 4:
                Form::addObjToDB(formArray, maxDbSizeForm, curDbSizeForm);
                break; 
            case 5:
                Form::deleteByName(formArray, curDbSizeForm);;
                break;
            case 6:
                Form::updateDb(formArray, curDbSizeForm);
                break;
            case 7:
                Form::printDb(formArray, curDbSizeForm);
                break;
            case 8:
                return 0;
            default:
                std::cout << " Недопустимый номер операции!" << std::endl;
                break;
        }
    }

    delete[] formArray;
    delete[] planetsArray;

    return 0;
}

/* TODO
Первая часть✅
    Описать класс планет ✅
        Поля ✅
        Cmake ✅
        Конструктор ✅
        Деструктор ✅
        Методы доступа к полям ✅

    База Данных
        структура хранениея + (2 инишил значениея)  ✅
        ---массив---
        добавление нового объекта в БД; ✅
        удаление объекта из БД; ✅
        редактирование БД; ✅
        вывод БД на экран; ✅
        сортировка БД; ✅
        ---файлы---
        чтение БД из файла; ✅ 
        запись БД в файл; ✅

Вторая часть
    Перегрузить >> ✅
    Перегрузить << ✅
    и использовать их в рабоче с файлами ✅

Третья часть
    перегрузить < ✅
    перегрузить == ✅
    использовать из в сортировке ✅

Чертвертая часть
    Описать класс опросов 
        Поля ✅
        Cmake ✅
        Конструктор ✅
        Деструктор ✅
        Методы доступа к полям ✅
    Интерактивное меню для взаимодействия с бд 

*/