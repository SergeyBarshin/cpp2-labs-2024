#ifndef INHERITANCE_MYSET_H
#define INHERITANCE_MYSET_H

#include <iostream>

#include "MyVector.hpp"

template <class T>
class MySet : public MyVector<T> {
   public:
    MySet(T el) : MyVector<T>(el){};
    MySet() : MyVector<T>(){};
    int q_find(T &el) const {
        // так так множество отсортировано ищем бинарным поиском
        return this->binarySearch(this->pdata, 0, this->size - 1, el);
    }

    bool operator==(MySet &s) {
        bool res = true;
        for (int i = 0; i < s.getSize(); ++i) {
            if (this->isElement(s[i]) == -1) {
                res = false;
                break;
            }
        }
        return res;
    }

    MySet &operator+=(const MySet &s) {
        for (int i = 0; i < s.getSize(); ++i) {
            if (!this->isElement(s[i])) this->AddElement(s[i]);
        }
        return *this;
    }

    MySet &operator-=(const MySet &s) {
        for (int i = 0; i < s.getSize(); ++i) {
            if (this->isElement(s[i])) this->deleteElement(s[i]);
        }
        return *this;
    }

    MySet &operator*=(const MySet &s) {
        for (int i = 0; i < s.getSize(); ++i) {
            if (!this->isElement(s[i])) this->deleteElement(s[i]);
        }
        return *this;
    }

    void AddElement(T el) {
        if (!isElement(el)) {
            this->addElement(el);
            this->sort();
        }
    }

    void deleteElement(T el) {
        int index;
        if (!(index = q_find(el))) {
            MyVector<T>::deleteElement(index);
        }
    }

    bool isElement(T el) const { return q_find(el) != -1; }
    // friend std::ostream &operator<<(std::ostream &out, MySet &s);
    friend MySet operator+(const MySet &s1, const MySet &s2) {
        MySet<T> tmp;
        tmp = s1;
        tmp += s2;
        return tmp;
    }
    friend MySet operator-(const MySet &s1, const MySet &s2) {
        MySet<T> tmp;
        tmp = s1;
        tmp -= s2;
        return tmp;
    }
    friend MySet operator*(const MySet &s1, const MySet &s2) {
        MySet<T> tmp;
        tmp = s1;
        tmp *= s2;
        return tmp;
    }
};

#endif  // INHERITANCE_MYSET_H
