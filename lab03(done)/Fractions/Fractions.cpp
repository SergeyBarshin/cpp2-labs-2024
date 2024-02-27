#include "Fractions.hpp"

unsigned int findNod(unsigned int a, unsigned int b) {
    if (a % b == 0)
        return b;
    if (b % a == 0)
        return a;
    if (a > b)
        return findNod(a%b, b);
    return findNod(a, b%a);
}


Fractions::Fractions(){
    num = 1;
    dem = 1;
}

Fractions::Fractions(int n, int d){
    if (d == 0){
        std::cout << "Ошибка! Деление на 0.\n";
        return;
    }

    int nod = findNod(n, d);
    num = n/nod;
    dem = d/nod;
}

Fractions::Fractions(const char* ch){

    int num1, num2, num3 = 0;
    if (strchr(ch, ' ')) {
        // Используем функцию sscanf для считывания значений из строки
        sscanf(ch, "%d %d/%d", &num1, &num2, &num3); // есть в C
        int ansNum = fabs(num1) * fabs(num3) + fabs(num2);
        int sign = (num1 < 0) ? -1 : 1;

        if (num3 == 0){
            std::cout << "Ошибка! Деление на 0.\n";
            return;
        }
        //int nod = findNod(ansNum, num3);

        num = ansNum * sign;
        dem = num3;

    } else {
        // Если целая часть не найдена
        sscanf(ch, "%d/%d",  &num2, &num3);
        if (num3 == 0){
            std::cout << "Ошибка! Деление на 0.\n";
            return;
        }
        //int nod = findNod(num2, num3);
        num = num2;
        dem = num3;

    }

    // находим НОД и округляем через него
    int nod = findNod(fabs(num), fabs(dem));
    num /= nod;
    dem /= nod;
}

Fractions::Fractions(double f){
    int sign = (f < 0) ? -1 : 1;
    double number = std::abs(f);

    // Выделяем целую часть
    int integerPart = static_cast<int>(number);
    
    // Вычисляем дробную часть
    double fractionalPart = number - integerPart;
    
    // Находим числитель и знаменатель дроби
    int numerator = static_cast<int>(fractionalPart * 1000000);
    int denominator = 1000000;

    int nod = findNod(numerator, denominator);
    numerator /= nod;
    denominator /= nod;

    int ansNum = fabs(integerPart) * fabs(denominator) + fabs(numerator);
    num = ansNum * sign;
    dem = denominator;
}



Fractions& Fractions::operator= (const Fractions& fr2){
    if (this != &fr2){ 
        this->num = fr2.num;
        this->dem = fr2.dem;
    }
    return *this;
}

Fractions& Fractions::operator= (const char* ch){
    Fractions t(ch);
    this->num = t.num;
    this->dem = t.dem;
    
    return *this;
}

Fractions& Fractions::operator= (double f){
    Fractions t(f);
    this->num = t.num;
    this->dem = t.dem;
    return *this;
}

Fractions operator+ (Fractions f1, Fractions f2){
    return Fractions(f1.num * f2.dem + f1.dem * f2.num, f1.dem * f2.dem); 
}

Fractions operator+ (double f, Fractions f2){
    Fractions f1(f);
    return Fractions(f1.num * f2.dem + f1.dem * f2.num, f1.dem * f2.dem); 
}

Fractions operator+ (Fractions f1, double f){
    Fractions f2(f);
    return Fractions(f1.num * f2.dem + f1.dem * f2.num, f1.dem * f2.dem); 
}

Fractions operator+ (int f, Fractions f2){
    Fractions f1(static_cast<double>(f));
    return Fractions(f1.num * f2.dem + f1.dem * f2.num, f1.dem * f2.dem); 
}

Fractions operator+ (Fractions f1, int f){
    Fractions f2(static_cast<double>(f));
    return Fractions(f1.num * f2.dem + f1.dem * f2.num, f1.dem * f2.dem); 
}

Fractions& Fractions::operator+= (Fractions f2){
    //std::cout << "-+=-" << n;
    //std::cout << f2.num << '/' << f2.dem << '\n';

   // std::cout << this->num << '/' << this->dem << '\n';
    Fractions n(this->num * f2.dem + this->dem * f2.num, this->dem * f2.dem);
    
    this->num = n.num;
    this->dem = n.dem;
    return *this;
}

Fractions& Fractions::operator+= (double f2){
    Fractions f(f2);
    Fractions n(this->num * f.dem + this->dem * f.num, this->dem * f.dem);
    this->num = n.num;
    this->dem = n.dem;
    return *this;
}

Fractions& Fractions::operator+= (int f2){
    Fractions f(static_cast<double>(f2));
    Fractions n(this->num * f.dem + this->dem * f.num, this->dem * f.dem);

    this->num = n.num;
    this->dem = n.dem;
    return *this;
}

std::istream & operator >> (std::istream &in, Fractions& fr){
    char tmp[50];
    in.getline(tmp, 50);
    Fractions t(tmp);
    if(t.dem == 0){
        std::cout << "Ошибка! Деление на 0.\n";
    }else{
        fr = t;
    }
    return in;
}

std::ostream & operator << (std::ostream &out, const Fractions& fr){
    if (fr.num == 0)
        out << 0;
    else if (fr.dem == 1)
        out << fr.num;
    else
    {
        if (abs(fr.num) < abs(fr.dem))
        {
            out << fr.num << "/" << fr.dem;
        }
        else
        {
            out << fr.num / fr.dem << " " << abs(fr.num % fr.dem) << "/" << fr.dem;
        }
    }
    return out;
}

// -1 9/12
// -123/6