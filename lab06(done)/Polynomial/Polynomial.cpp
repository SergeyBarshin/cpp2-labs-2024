#include "Polynomial.hpp"

void removeSpaces(char* str) {
    int length = strlen(str);
    str[length] = '\0';  // Установить нулевой символ в конце
    // Удаление пробелов с использованием remove_if и лямбда-функции
    str = std::remove_if(str, str + length, [](unsigned char c) { return std::isspace(c); });
    *str = '\0';  // Установить нулевой символ в конце
}

std::pair<int, int> parceStrToTerm(char* str) {
    bool x = false, pow = false;

    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == 'x') x = true;
        if (str[i] == '^') pow = true;
    }

    int pos_x = -1;
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == 'x') {
            pos_x = i;
            break;
        }
    }

    // выше мы определяем на наличие x и числа в степени

    bool isDigitBeforex = pos_x != -1 ? isdigit(str[pos_x - 1]) : true;
    // std::cout << isDigitBeforex << '\n';
    int coef = 1, power = 0;
    if (isDigitBeforex) {
        sscanf(str, "%dx^%d", &coef, &power);
    } else {
        if (pow) {
            char* pos_power = strchr(str, '^');
            sscanf(pos_power + 1, "%d", &power);
        }
    }

    if (!pow) power = 1;
    if (!x) power = 0;
    if (coef == 1 && str[0] == '-') coef = -coef;
    // std::cout << coef << ' ' << power << '\n';
    return {coef, power};
}

Term operator+(const Term& t1, const Term& t2) {
    if (t1.getExp() != t2.getExp()) {
        std::cerr << "Error: "
                  << "Нельзя складывать члены разных степеней!!!!" << std::endl;
        exit(0);
        // return 0;
    }

    Term newTerm(t1.getInt() + t2.getInt(), t1.getExp());
    return newTerm;
};

Term& Term::operator=(const Term& tr) {
    this->_coef = tr.getInt();
    this->_exp = tr.getExp();
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Term& tr) {
    if (tr._coef == -1)
        out << "- ";
    else if (tr._coef != 1) {
        if (tr._coef < 0)
            out << "- " << -tr._coef;
        else
            out << tr._coef;
    }

    if (tr._exp == 0) {
        return out;
    } else if (tr._exp == 1) {
        out << 'x';
    } else {
        out << "x^" << tr._exp;
    }
    return out;
}

std::istream& operator>>(std::istream& in, Term& fr) {
    char str[50];
    std::cin.getline(str, 50);
    removeSpaces(str);
    auto [coef, power] = parceStrToTerm(str);
    if (coef != 0) {
        fr._coef = coef;
        fr._exp = power;
    } else {
        fr._coef = 0;
        fr._exp = 0;
    }

    return in;
}

/*Polynomial::Polynomial(int coef) {
    Term tr(coef);
    _poly.addElement(tr);
}*/

Polynomial::Polynomial(int coef, int exp) {
    Term tr(coef, exp);
    _poly.addElement(tr);
}

Polynomial::Polynomial(const Polynomial& pl) { _poly = pl._poly; }

Polynomial& Polynomial::operator+=(const Term& tr) {
    // находим полином нашей стерени и прибовляем к нему, получем newPl
    if (tr._exp == 0 && tr._coef == 0) return *this;
    for (int i = 0; i < _poly.getSize(); ++i) {
        if (_poly[i].getExp() == tr.getExp()) {
            _poly[i] = _poly[i] + tr;
            return *this;
        }
    }

    _poly.addElement(tr);  // добавляем элемент и сортируем, сортировка по _order
    _poly.sort(_order);
    return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial& pl) {
    // идем по каждому элементу pl и +=
    for (int i = 0; i < pl._poly.getSize(); ++i) {
        *this += pl._poly[i];
    }
    return *this;
}

Polynomial operator+(const Polynomial& pl1, const Term& tr) {
    Polynomial temp(pl1);
    temp += tr;
    return temp;
}

Polynomial operator+(const Polynomial& pl1, const Polynomial& pl2) {
    Polynomial temp(pl1);
    for (int i = 0; i < pl2._poly.getSize(); ++i) {
        temp += pl2._poly[i];
    }
    return temp;
}

Polynomial& Polynomial::operator*=(const Term& tr) {
    // проходим по каждому элементу и умножаем коэфы, кладываем степени
    for (int i = 0; i < _poly.getSize(); ++i) {
        _poly[i]._coef *= tr._coef;
        _poly[i]._exp += tr._exp;
    }
    return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& pl) {
    // идем по каждому элементу pl и +=
    for (int i = 0; i < pl._poly.getSize(); ++i) {
        *this *= pl._poly[i];
    }
    return *this;
}

Polynomial operator*(const Polynomial& pl1, const Term& tr) {
    Polynomial temp(pl1);
    temp *= tr;
    return temp;
}

Polynomial operator*(const Polynomial& pl1, const Polynomial& pl2) {
    Polynomial temp(pl1);
    for (int i = 0; i < pl2._poly.getSize(); ++i) {
        temp *= pl2._poly[i];
    }
    return temp;
}

std::ostream& operator<<(std::ostream& out, const Polynomial& pl) {
    if (pl._poly.getSize() == 0)
        return out << 0;
    else {
        for (int i = 0; i < pl._poly.getSize() - 1; i++) {
            out << pl._poly[i];
            if (pl._poly[i + 1].getInt() > 0)
                out << " + ";
            else
                out << ' ';
        }
        out << pl._poly[pl._poly.getSize() - 1];
        return out;
    }
}

std::istream& operator>>(std::istream& in, Polynomial& pl) {
    // char str[] = "     +   3x^2 - x^2 -    3x^2 + x ^2 + 5x^5   - 4x^3 +x^2 - 7";
    char str[1000];
    std::cin.getline(str, 1000);
    removeSpaces(str);

    // считаем где находится какой знак
    MyVector<char> simbs;
    int startpos = 0;
    if (str[0] != '-') {
        startpos = 1;
        simbs.addElement('+');
    }
    for (int i = startpos; i < strlen(str); i++) {
        if (str[i] == '-') simbs.addElement('-');
        if (str[i] == '+') simbs.addElement('+');
    }

    // делим подстроку на токены, определяем номер токена, записываем к нему знак
    const char* delim = "+-";
    char* token = strtok(str, delim);
    int simbIndex = 0;

    while (token != NULL) {
        char tmpStr[strlen(token) + 2];
        tmpStr[0] = simbs[simbIndex];

        strcat(tmpStr, token);
        auto [coef, power] = parceStrToTerm(tmpStr);
        if (coef == 0) power = 0;
        Term tmp(coef, power);
        token = strtok(NULL, delim);
        simbIndex += 1;
        pl += tmp;
    }

    return in;
};
