#include <iomanip>
#include <iostream>

#include "MyLib/MyLib.hpp"

Worker* Worker::head = nullptr;
bool Worker::addOnCreate = true;

int main() {
    Administration adm1("Иванов", 1000);
    HR hr1("Петров", 1200, "Отдел1");
    Engineer eng1("Сидоров", 1300, 3);
    Worker::print();

    HR hr2;
    hr2 = hr1;

    Worker::print();

    Engineer eng2;
    eng2 = eng1;

    Administration adm2 = adm1;
    Worker::print();

    return 0;
}
// Иванов Петров Сидоров Иванов Петров Сидоров