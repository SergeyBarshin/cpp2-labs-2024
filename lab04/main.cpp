#include "MyStack/MyStack.hpp"

template <class DATA>
void Multipliers(int n, MyStack<DATA> &stack)
{
    while (n % 2 == 0)
    {
        stack.push(2);
        n = n / 2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            stack.push(i);
            n = n / i;
        }
    }

    if (n > 2)
        stack.push(n);
}

int main()
{
    int n = 3960;
    MyStack<int> stack;
    MyStack<int> stackReverse; // стек в который мы перезапишем значения

    Multipliers<int>(n, stack);
    std::cout << n << "=";
    while (!stack.empty())
    {
        std::cout << stack.top_inf();
        stackReverse.push(stack.top_inf());
        stack.pop();

        if (!stack.empty())
            std::cout << " * ";
    }
    std::cout << std::endl;

    std::cout << n << "=";
    while (!stackReverse.empty())
    {
        std::cout << stackReverse.top_inf();
        stackReverse.pop();
        if (!stackReverse.empty())
            std::cout << " * ";
    }
    std::cout << std::endl;

    // std::cout << stack.top_inf() << '\n';
    //  std::cout << stack.empty() << '\n';

    return 0;
}