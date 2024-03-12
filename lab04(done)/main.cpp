#include "MyStack/MyStack.hpp"

template <class DATA>
void Multipliers(int n, MyStack<DATA> &stack) {
    int tmpN = abs(n);
    bool flag = false;

    while (tmpN % 2 == 0 && tmpN != 0) {
        if (!flag && n < 0) {
            stack.push(-2);
            flag = true;
        } else {
            stack.push(2);
        }
        tmpN = tmpN / 2;
    }

    for (int i = 3; i <= sqrt(tmpN); i = i + 2) {
        while (tmpN % i == 0) {
            if (!flag && n < 0) {
                stack.push(i * -1);
                flag = true;
            } else {
                stack.push(i);
            }
            tmpN = tmpN / i;
        }
    }

    if (tmpN > 2) {
        if (!flag && n < 0) {
            stack.push(tmpN * -1);
            flag = true;
        } else {
            stack.push(tmpN);
        }
    }
}

int main() {
    int n = 3690;
    MyStack<int> stack;
    MyStack<int> stackReverse;  // стек в который мы перезапишем значения
    Multipliers<int>(n, stack);

    std::cout << n << "=";
    while (!stack.empty()) {
        std::cout << stack.top_inf();
        stackReverse.push(stack.top_inf());
        stack.pop();

        if (!stack.empty()) std::cout << " * ";
    }
    std::cout << std::endl;

    std::cout << n << "=";
    while (!stackReverse.empty()) {
        std::cout << stackReverse.top_inf();
        stackReverse.pop();
        if (!stackReverse.empty()) std::cout << " * ";
    }
    std::cout << std::endl;

    return 0;
}