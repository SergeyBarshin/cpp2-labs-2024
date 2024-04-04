#include "Polynomial/Polynomial.hpp"
// #include "Polynomial/Term.hpp"

int main() {
    Term term1(-1, 2);
    Term term2(4, 2);
    Term term3(6, 3);
    Term term4(12, 0);
    Term term5(1, 2);  // x^2

    Polynomial poly(12, 5);
    std::cout << poly << '\n';

    poly += term1;
    poly += term2;
    poly += term3;
    poly += term4;
    std::cout << poly << '\n';

    Polynomial poly2;
    std::cin >> poly2;
    std::cout << "введеный полином (poly2): " << poly2 << '\n';

    Polynomial poly3;
    poly3 = poly2 + poly;
    std::cout << poly3 << '\n';

    Polynomial poly4(poly2);
    std::cout << poly4 << '\n';

    poly4 += poly;
    std::cout << poly4 << '\n';
    poly4 += term4;
    std::cout << poly4 << '\n';

    std::cout << "\t"
              << "Дальше проверка умножний\n";
    poly4 *= term4;
    std::cout << "poly4: " << poly4 << '\n';
    poly4 *= term5;
    std::cout << poly4 << '\n';

    Polynomial poly5;
    poly5 = poly4 * term2;
    std::cout << "poly5: " << poly5 << '\n';

    Polynomial poly6(poly);
    std::cout << "poly6: " << poly6 << '\n';

    poly6 *= poly;
    std::cout << "poly6: " << poly6 << '\n';

    poly6 = poly;
    poly6 = poly6 * poly;
    std::cout << "poly6: " << poly6 << '\n';
    std::cout << "--------" << '\n';
    Polynomial poly7;
    poly7 = poly + 3;
    std::cout << poly7 << '\n';
    return 0;
}

/*TODO

    операторы * *=
*/

// 5x^5 -4x^3 +x^2 - 7
// 3x^2 - x^2 -    3x^2 + x ^2 + 5x^5   - 4x^3 +x^2 - 7

// 3x^2 - x^2 -    3x^2 + x ^2 + 5x^5   - 4x^3 +x^2 - 7 + x + x + x + 0x + x^1 - x  ^ 1

// 5x^5 - 4x^3 + x^2 + 3x - 7