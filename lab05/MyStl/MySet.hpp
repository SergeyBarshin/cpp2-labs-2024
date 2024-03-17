#ifndef INHERITANCE_MYSET_H
#define INHERITANCE_MYSET_H

#include <iostream>

#include "MyVector.hpp"

template <class T>
class MySet : public MyVector<T> {
   public:
    MySet(T el = 0) : MyVector<T>(el){};
    int q_find(const T &el) const {
        // так так множество отсортировано ищем бинарным поиском
        return MyVector<T>::binarySearch(MyVector<T>::pdata, 0, MyVector<T>::size, el);
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
            if (this->isElement(s[i])) this->DeleteElement(s[i]);
        }
        return *this;
    }

    MySet &operator*=(const MySet &s) {
        for (int i = 0; i < s.getSize(); ++i) {
            if (!this->isElement(s[i])) this->DeleteElement(s[i]);
        }
        return *this;
    }

    void AddElement(const T el) {
        if (q_find(el) == -1) {
            this->addElement(el);
            this->sort();
        }
    }

    void DeleteElement(T el) {
        int index;
        if (!(index = q_find(el))) {
            this->deleteElement(index);
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

template <>
class MySet<char *> : public MyVector<char *> {
   public:
    MySet(const char *el = NULL) : MyVector<char *>(el){};

    int q_find(const char *el) const {
        // так так множество отсортировано ищем бинарным поиском
        return this->binarySearch(this->pdata, 0, this->size - 1, el);
    }

    bool operator==(MySet &s) {
        bool res = true;
        for (int i = 0; i < s.getSize(); ++i) {
            if (!this->isElement(s[i])) {
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
            if (this->isElement(s[i])) this->DeleteElement(s[i]);
        }
        return *this;
    }

    MySet &operator*=(const MySet &s) {
        for (int i = 0; i < this->getSize(); ++i) {
            std::cout << s[i] << '\n';

            if (!s.isElement(this->pdata[i])) {
                this->deleteElement(i);  // удаление по индексу
            }
        }
        return *this;
    }

    void AddElement(const char *el) {
        if (!isElement(el)) {
            this->addElement(el);

            this->sort();
        }
    }

    void DeleteElement(const char *el) {
        int index;
        if ((index = q_find(el)) != -1) {
            this->deleteElement(index);
        }
    }

    bool isElement(const char *el) const { return q_find(el) != -1; };
    // friend std::ostream &operator<<(std::ostream &out, MySet &s);
    friend MySet operator+(const MySet &s1, const MySet &s2) {
        MySet<char *> tmp;
        tmp = s1;
        tmp += s2;
        return tmp;
    }
    friend MySet operator-(const MySet &s1, const MySet &s2) {
        MySet<char *> tmp;
        tmp = s1;
        tmp -= s2;
        return tmp;
    }
    friend MySet operator*(const MySet &s1, const MySet &s2) {
        MySet<char *> tmp;
        tmp = s2;
        tmp *= s2;
        return tmp;
    }
};
#endif  // INHERITANCE_MYSET_H
