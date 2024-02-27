#include "mymath.h"

namespace mymath {
    int sum(int a, int b) {
        return a + b;
    }

    int mul(int a, int b) {
        return a * b;
    }

    int factorial(int a) {
        int fact = 1;
        for (int i = 1; i <= a; i++) { 
            fact = fact * i; 
        } 
        return fact;
    }
}