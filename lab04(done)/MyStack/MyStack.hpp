// Файл MyStack.h
// Шаблонный класс MyStack на основе односвязного списка.
#ifndef MyStack_h  // защита от повторной компиляции
#define MyStack_h  // модуль подключен
#include <iostream>

// Шаблонный класс ListNode (узел односвязного списка)
template <class INF, class FRIEND>
class ListNode {  // узел списка
   private:
    INF d;                              // информационная часть узла
    ListNode *next;                     // указатель на следующий узел списка
    ListNode(void) { next = nullptr; }  // конструктор
    //~ListNode(void) { delete next; }
    // ListNode(INF n) { d = n; }
    friend FRIEND;
};

// Шаблонный класс MyStack на основе односвязного списка.
template <class INF>
class MyStack {
    typedef class ListNode<INF, MyStack<INF> > Node;
    Node *top;

   public:
    MyStack(void) {  // конструктор
        top = nullptr;
    }

    ~MyStack(void) {  // освободить динамическую память
        while (!empty()) {
            pop();
        }
    }

    bool empty(void) {  // стек пустой?
        return top == nullptr;
    }

    MyStack(const MyStack &p) {
        MyStack<INF> tmp1;
        Node *tmpNode = p.top;

        while (tmpNode) {
            tmp1.push(tmpNode->d);
            tmpNode = tmpNode->next;
        }

        top = nullptr;
        while (!tmp1.empty()) {
            push(tmp1.top_inf());
            tmp1.pop();
        }
    }

    MyStack &operator=(const MyStack &p2) {
        MyStack<INF> tmp1;
        Node *tmpNode = p2.top;

        while (tmpNode) {
            tmp1.push(tmpNode->d);
            tmpNode = tmpNode->next;
        }

        top = nullptr;
        while (!tmp1.empty()) {
            this->push(tmp1.top_inf());
            tmp1.pop();
        }
        return *this;
    }

    void push(INF n) {  // добавить узел в вершину стека
        Node *temp = new Node;
        temp->d = n;
        temp->next = top;
        top = temp;
        // top = top->next;
    }

    void pop(void) {  // удалить узел из вершины стека
        if (empty()) {
            std::cout << "Стек пуст, невозможно получить значение!" << std::endl;
            return;
        } else {
            Node *temp;
            temp = top;
            top = top->next;
            delete temp;
        }
    }

    INF top_inf(void) {  // считать информацию из вершины стека
        if (empty()) {
            std::cout << "Стек пуст, невозможно получить значение!" << std::endl;
            return -1;
        }
        return top->d;
    }
};

#endif