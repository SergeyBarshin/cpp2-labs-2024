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

   public:
    MyVector(T el = 0, int max_size = MAX_SIZE) {
        maxSize = MAX_SIZE;
        pdata = new T[maxSize];
        if (!el) {
            size = 0;
        } else {
            pdata[0] = el;
            size = 1;
        }
    };

    /*  MyVector(const T el, int max_size = MAX_SIZE) {
          size = 1;
          maxSize = MAX_SIZE;
          pdata = new T *[maxSize];
          pdata[0] = el;
          // strcpy(pdata[0], el);
      };*/

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

    T operator[](int i) const {
        if (i >= size) {
            std::cerr << "Выход за пределы границ вектора\n";
            return 0;
        } else {
            return pdata[i];
        }
    }
    // функции для алгоритмы бысторой сортировки

    int partition(T *arr, int low, int high) {
        T pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }

        std::swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    void quickSort(T *arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);

            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    void sort() { quickSort(pdata, 0, size - 1); };
    // конец сортировки

    int getSize() const { return size; }
    int getMaxSize() const { return maxSize; }

    int find(T el) const {
        for (int i = 0; i < size; ++i) {
            if (pdata[i] == el) {
                return i;
            }
        }
        return -1;
    }
    int binarySearch(T *arr, int l, int r, int x) const {
        while (l <= r) {
            int m = l + (r - l) / 2;

            // Check if x is present at mid
            if (arr[m] == x) return m;

            // If x greater, ignore left half
            if (arr[m] < x) l = m + 1;

            // If x is smaller, ignore right half
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

/* --------------------------------------------------------*/
// специализация шаблона под char*
template <>
class MyVector<char *> {
   protected:
    int maxSize;
    int size;
    char **pdata;

    void resize(int newSize) {
        if (size >= maxSize || size <= maxSize / 2) {
            char **newArr = new char *[newSize];
            for (int i = 0; i < size; ++i) {
                newArr[i] = new char(strlen(pdata[i] + 1));
                newArr[i] = pdata[i];
            }
            delete[] pdata;
            pdata = newArr;
            maxSize = newSize;
        }
    };

   public:
    MyVector(char *el = NULL, int max_size = MAX_SIZE) {
        size = 1;
        maxSize = MAX_SIZE;
        pdata = new char *[maxSize];
        if (!el) {
            pdata[0] = new char[1];
        } else {
            pdata[0] = new char[strlen(el) + 1];
            strcpy(pdata[0], el);
        }
    };

    MyVector(const char *el, int max_size = MAX_SIZE) {
        size = 1;
        maxSize = MAX_SIZE;
        pdata = new char *[maxSize];
        if (!el) {
            pdata[0] = new char[1];
        } else {
            pdata[0] = new char[strlen(el) + 1];
            strcpy(pdata[0], el);
        }
    };

    MyVector(const MyVector &v) {
        // size = 0;
        maxSize = MAX_SIZE;
        pdata = new char *[MAX_SIZE];
        for (int i = 0; i < v.getSize(); ++i) {
            addElement(v.pdata[i]);
        }
    };

    ~MyVector() {
        for (int i = 0; i < size; i++) {
            delete[] pdata[i];
        }
        delete[] pdata;
    };

    void addElement(const char *el) {
        pdata[size] = new char[strlen(el) + 1];
        strcpy(pdata[size], el);
        size++;
        resize(maxSize * 2);
    };

    bool deleteElement(int i) {
        if (i < size) {
            for (int j = i + 1; j < size; ++j) {
                strcpy(pdata[j - 1], pdata[j]);
            }
            --size;
            resize(maxSize / 2);
        } else {
            std::cerr << "Выход за пределы границ вектора\n";
        }
        return false;
    };

    char *operator[](int i) const {
        if (i >= size) {
            std::cerr << "Выход за пределы границ вектора\n";
            return nullptr;
        } else {
            return pdata[i];
        }
    }
    // функции для алгоритмы бысторой сортировки
    void swap(char **a, char **b) {
        char *temp = *a;
        *a = *b;
        *b = temp;
    }

    int partition(char **arr, int low, int high) {
        char *pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (strcmp(arr[j], pivot) < 0) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }

        swap(&arr[i + 1], &arr[high]);
        return i + 1;
    }

    void quickSort(char **arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);

            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    void sort() { quickSort(pdata, 0, size - 1); };

    int getSize() const { return size; }
    int getMaxSize() const { return maxSize; }

    int find(const char *el) const {
        for (int i = 0; i < size; ++i) {
            if (strcmp(pdata[i], el) == 0) {
                return i;
            }
        }
        return -1;
    }

    int binarySearch(char **arr, int l, int r, const char *x) const {
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (strcmp(arr[m], x) == 0) return m;

            if (strcmp(arr[m], x) < 0)
                l = m + 1;

            else
                r = m - 1;
        }
        return -1;
    }

    MyVector &operator=(const MyVector &v) {
        this->maxSize = v.getMaxSize();
        this->size = v.getSize();

        char **newArr = new char *[maxSize];

        for (int i = 0; i < size; ++i) {
            newArr[i] = new char(strlen(v[i] + 1));
            strcpy(newArr[i], v[i]);
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

#endif  // INHERITANCE_MYVECTOR_H
