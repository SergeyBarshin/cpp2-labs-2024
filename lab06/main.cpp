#include "Polynomial/Polynomial.hpp"
// #include "Polynomial/Term.hpp"

int main() {
    Term term1(-1, 2);
    Term term2(4, 2);
    Term term3(6, 3);
    Term term4(12, 0);

    Polynomial poly(12, 5);
    std::cout << poly << '\n';

    poly += term1;
    poly += term2;
    poly += term3;
    poly += term4;
    std::cout << poly << '\n';

    Polynomial poly2;
    std::cin >> poly2;
    std::cout << poly2 << '\n';

    Polynomial poly3;
    poly3 = poly2 + poly;
    std::cout << poly3 << '\n';

    return 0;
}

/*TODO

    операторы * *=
*/

// 5x^5 -4x^3 +x^2 - 7
// 3x^2 - x^2 -    3x^2 + x ^2 + 5x^5   - 4x^3 +x^2 - 7