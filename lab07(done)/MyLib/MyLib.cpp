#include "MyLib.hpp"

Worker::Worker() {
    _name = new char[1];
    _name[0] = '\0';
    if (addOnCreate) add();
}

Worker::Worker(const char* name) {
    _name = new char[strlen(name) + 1];
    strcpy(_name, name);
    if (addOnCreate) add();
}

Worker::Worker(const Worker& other) {
    _name = new char[strlen(other._name) + 1];
    strcpy(_name, other._name);
    if (addOnCreate) add();
}

Worker::~Worker() { delete[] _name; }

Worker& Worker::operator=(const Worker& other) {
    if (this != &other) {
        delete[] this->_name;
        this->_name = new char[strlen(other._name) + 1];
        strcpy(this->_name, other._name);
    }
    return *this;
}

HR::HR() : Administration() {
    _department = new char[1];
    _department[0] = '\0';
}

HR::HR(const char* name, int salary, const char* department) : Administration(name, salary) {
    _department = new char[strlen(name) + 1];
    strcpy(_department, department);
};

HR::HR(const HR& other) : Administration(other) {
    _department = new char[strlen(other._department) + 1];
    strcpy(_department, other._department);
};

HR& HR::operator=(const HR& other) {
    Administration::operator=(other);
    if (this != &other) {
        delete[] this->_department;
        this->_department = new char[strlen(other._department) + 1];
        strcpy(this->_department, other._department);

        //        this->_salary = other._salary;
    }
    return *this;
}

char* Worker::getName() const { return _name; }

std::ostream& operator<<(std::ostream& out, const Worker& obj) { return out << obj._name; }

void Worker::add() {
    this->next = head;
    head = this;
}

void HR::show() const { std::cout << _name << '-' << _salary << '-' << _department << "\n"; }

void Administration::show() const { std::cout << _name << "-" << _salary << "\n"; }

void Engineer::show() const { std::cout << _name << '-' << _salary << '-' << _category << "\n"; }

void Worker::print() {
    Worker* cur = head;
    while (cur) {
        cur->show();
        cur = cur->next;
    }
    std::cout << '\n';
}
