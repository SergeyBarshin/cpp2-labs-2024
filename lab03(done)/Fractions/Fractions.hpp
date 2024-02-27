#include <fstream>
#include <iostream>

class Fractions{
    
    private:
        int num; // числитель
        int dem; // знаменатель

    public:
        Fractions();
        Fractions(int n, int d);
        Fractions(const char* ch);
        Fractions(double f);
        //Fractions(const Fractions &f);

        Fractions& operator= (const Fractions& fr2);
        Fractions& operator= (const char* ch);
        Fractions& operator= (double f);

        friend Fractions operator+ (Fractions f1, Fractions f2);
        friend Fractions operator+ (double f1, Fractions f2);
        friend Fractions operator+ (Fractions f1, double f2);
        friend Fractions operator+ (int f1, Fractions f2);
        friend Fractions operator+ (Fractions f1, int f2);

        Fractions& operator+= ( Fractions f2);
        Fractions& operator+= (double f2);
        Fractions& operator+= (int f2);

        friend std::ostream & operator << (std::ostream &out, const Fractions& fr);
        friend std::istream & operator >> (std::istream &in, Fractions& fr);

};