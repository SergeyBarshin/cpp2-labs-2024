#include <iostream>
#include <cstring>
#include "mymath/mymath.h"
#include "secLib/secLib.h"

int main() {
    // setlocale(LC_ALL, "Russian");
    
    std::cout << mymath::sum(14,18) << " - cумма 14 и 18" <<  std::endl;
    std::cout << mymath::mul(14,18) << " - произведение 14 и 18" <<  std::endl;
    std::cout << mymath::factorial(14) << " - факториал 14" <<  std::endl;

    std::cout << "Далее будут ф-ции из второй библиотеки" <<  std::endl;
    secLib::helloWrld();
    secLib::buebue();
    return 0;
}
