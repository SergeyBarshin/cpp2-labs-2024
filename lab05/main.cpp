#include <iostream>

// #include "MyStl/MySet.hpp"
#include "MyStl/MyVector.hpp"

int main() {
    // MyVector<int> v(0);
    MyVector<int> v;
    v.addElement(9);
    v.addElement(8);
    v.addElement(7);
    v.addElement(6);
    v.addElement(5);
    std::cout << "Вектор v: " << v << std::endl;
    v.addElement(4);
    v.addElement(3);
    v.addElement(2);
    std::cout << "Вектор v: " << v << std::endl;
    MyVector<int> v1 = v;
    std::cout << "Вектор v1: " << v1 << std::endl;
    for (int i = 0; i < MAX_SIZE; i++) v1.deleteElement(0);
    std::cout << "Вектор v1: " << v1 << std::endl;

    MyVector<int> v2;
    v2 = v;
    v2.sort();

    std::cout << "Отсортированный  v2: " << v2 << std::endl;
    std::cout << "найдем v2: " << v2.find("Привет!-") << std::endl;

    /* MySet s("Yes"), s1, s2;
     s.AddElement("Привет!");
     s.AddElement("No");
     char *str = "Hello!";
     s.AddElement(str);
     std::cout << "Множество s: " << s << std::endl;
     s1.AddElement("Cat");
     s1.AddElement("No");
     s1.AddElement("Привет!");
     std::cout << "Множество s1: " << s1 << std::endl;
     s2 = s1 - s;
     std::cout << "Множество s2=s1-s: " << s2 << std::endl;
     std::cout << "Множество s1: " << s1 << std::endl;
     std::cout << "Множество s: " << s << std::endl;
     s2 = s - s1;
     std::cout << "Множество s2=s-s1: " << s2 << std::endl;
     std::cout << "Множество s1: " << s1 << std::endl;
     std::cout << "Множество s: " << s << std::endl;
     s2 = s1 + s;
     std::cout << "Множество s2=s1+s: " << s2 << std::endl;
     std::cout << "Множество s1: " << s1 << std::endl;
     std::cout << "Множество s: " << s << std::endl;
     s2 = s1 * s;
     std::cout << "Множество s2=s1*s: " << s2 << std::endl;
     std::cout << "Множество s1: " << s1 << std::endl;
     std::cout << "Множество s: " << s << std::endl;
     MySet s3 = s2;
     std::cout << "Множество s3=s2: " << s3 << std::endl;
     if (s3 == s2)
         std::cout << "Множество s3=s2\n";
     else
         std::cout << "Множество s3!=s2\n";
     if (s3 == s1)
         std::cout << "Множество s3=s1\n";
     else
         std::cout << "Множество s3!=s1\n";
     if (s1 == s3)
         std::cout << "Множество s1=s3\n";
     else
         std::cout << "Множество s1!=s3\n";*/

    return 0;
}

/* TODO
    - MyVector
        Конструктор по умолчанию ✅
        addElement ✅
        raloc ✅
        << ✅
        копированние ✅
        delete ✅
        [] ✅
        = ✅
        find ✅
        sort ✅
        Сделать шаблонным
            сделать общий шаблон
            сделать char* специалица

    - MySet

*/