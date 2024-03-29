#ifndef INHERITANCE_MYVECTOR_H
#define INHERITANCE_MYVECTOR_H

#include <iostream>

const int MAX_SIZE = 5;

template <class T>
class MyVector {
   protected:
    int maxSize;
    int size;
    T *pdata;

    void resize(int newSize) {
        if (size >= maxSize || size <= maxSize / 2) {
            T *newArr = new T[newSize];
            for (int i = 0; i < size; ++i) {
                newArr[i] = pdata[i];
            }
            delete[] pdata;
            pdata = newArr;
            maxSize = newSize;
        }
    };

    void insertionSort(T *arr, int n, bool order) {
        int i, j;
        T key;
        for (i = 1; i < n; i++) {
            key = arr[i];
            j = i - 1;

            while (j >= 0 && ((arr[j].getExp() > key.getExp()) && order) ||
                   ((arr[j].getExp() < key.getExp()) && !order)) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

   public:
    MyVector() {
        maxSize = MAX_SIZE;
        pdata = new T[maxSize];
        size = 0;
    };

    MyVector(const T el) {
        maxSize = MAX_SIZE;
        pdata = new T[maxSize];
        if (!el) {
            size = 0;
        } else {
            pdata[0] = el;
            size = 1;
        }
    };

    MyVector(const MyVector &v) {
        // size = 0;
        maxSize = MAX_SIZE;
        pdata = new T[MAX_SIZE];
        for (int i = 0; i < v.getSize(); ++i) {
            addElement(v.pdata[i]);
        }
    };

    ~MyVector() { delete[] pdata; };

    void addElement(const T el) {
        pdata[size] = el;
        size++;
        resize(maxSize * 2);
    };

    bool deleteElement(int i) {
        if (i < size) {
            for (int j = i + 1; j < size; ++j) {
                pdata[j - 1] = pdata[j];
            }
            --size;
            resize(maxSize / 2);
        } else {
            std::cerr << "Выход за пределы границ вектора\n";
        }
        return false;
    };

    T &operator[](int i) const { return pdata[i]; }

    void sort(bool order) {
        // quickSort(pdata, 0, size - 1);
        insertionSort(pdata, size, order);
    };
    // конец сортировки

    int getSize() const { return size; }

    int getMaxSize() const { return maxSize; }

    int find(const T el) const {
        for (int i = 0; i < size; ++i) {
            if (pdata[i] == el) {
                return i;
            }
        }
        return -1;
    }
    int binarySearch(T *arr, int l, int r, T x) const {
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] == x) return m;
            if (arr[m] < x)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }

    MyVector &operator=(const MyVector &v) {
        this->maxSize = v.getMaxSize();
        this->size = v.getSize();

        T *newArr = new T[maxSize];

        for (int i = 0; i < size; ++i) {
            newArr[i] = v[i];
        }
        this->pdata = newArr;

        return *this;
    };

    friend std::ostream &operator<<(std::ostream &out, const MyVector &v) {
        for (int i = 0; i < v.getSize(); i++) {
            out << v.pdata[i] << ' ';
        }
        return out;
    };
};
#endif