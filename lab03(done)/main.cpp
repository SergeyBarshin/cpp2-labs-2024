#include "Fractions/Fractions.hpp"


int main(){
    std::cout << "Введите дробь: \n";
    Fractions z;
    std::cin >> z;
    std::cout << "z=" << z << std::endl;
    // проверка конструкторов
    Fractions fr1(10, 14), fr2;
    std::cout << "fr2=" << fr2 << std::endl;
    std::cout << "fr1=" << fr1 << std::endl;
    Fractions fr = "-1 4/8";
    std::cout << "fr=" << fr << std::endl;
    Fractions x(z), y;
    std::cout << "x=" << x << std::endl;
    double dbl = -1.25;
    Fractions f = dbl;
    std::cout << "f=" << f << std::endl;
    // проверка перегруженной операции "+"
    y = x + z;
    std::cout << "y=" << y << std::endl;
    y += x;
    f += dbl / 2;
    std::cout << "f=" << f << std::endl;
    y = x + dbl;
    std::cout << "y=" << y << std::endl;
    y = dbl + y;
    std::cout << "y=" << y << std::endl;
    y += dbl;
    std::cout << "y=" << y << std::endl;
    int i = 5;
    y += i;
    std::cout << "y=" << y << std::endl;
    y = i + x;
    std::cout << "y=" << y << std::endl;
    y = x + i;
    std::cout << "y=" << y << std::endl;
    y += dbl + i + x;
    std::cout << "y=" << y << std::endl;
    return 0;
}

/*TODO
    - Настройка проекта (cmake) ✅
    - Создание класса
        - Поля ✅
        - Конструкторы
            - пустой ✅
            - int int ✅
            - копирования ✅
            - строки char* ✅
            - double ✅
        - Операторы
            - ввод (конструктор char*) ✅
            - вывод с форматированием ✅
            - + ✅
            - += 
            - присваивание строки ✅
            - присваивание double ✅
            - присваивание объекта ✅
        - fix
            - обрабатывать деление на 0 при вводе и конструкторах ✅
*/