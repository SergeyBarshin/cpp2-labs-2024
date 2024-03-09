#include "MyStack/MyStack.hpp"


int main(){
    MyStack<int> stack;

    //std::cout << stack.empty() << '\n';
    stack.push(1);
    std::cout << stack.top_inf() << '\n';
    stack.push(2);
    stack.push(3);
    std::cout << stack.top_inf() << '\n';
    stack.pop();
    std::cout << stack.top_inf() << '\n';
    stack.pop();
    stack.pop();
    std::cout << stack.empty() << '\n';


    return 0;
}