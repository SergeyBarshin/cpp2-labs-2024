#include <iostream>
#include <ostream>

/*
    рабочий        -> администрация(оклад) -> инженер(int категория)
                                           -> кадры(str отдел)

*/

class Worker {
   public:
    Worker();
    Worker(const char* name);
    Worker(const Worker& other);
    Worker& operator=(const Worker& other);
    virtual ~Worker();

    char* getName() const;

    friend std::ostream& operator<<(std::ostream& out, const Worker& obj);

    virtual void who() const = 0;
    virtual void show() const = 0;

    void add();
    static void print();

    Worker* next = nullptr;

   protected:
    char* _name;

    static Worker* head;
    static bool addOnCreate;
};

class Administration : public Worker {
   public:
    Administration() : Worker(){};
    Administration(const char* name, int salary) : Worker(name), _salary(salary){};
    Administration(const Administration& other) : Worker(other), _salary(other._salary){};
    virtual ~Administration(){};

    void who() const override { std::cout << _name << " работает в администации\n"; }
    void show() const override;

   protected:
    int _salary;
};

class HR : public Administration {
   public:
    HR();
    HR(const char* name, int salary, const char* department);
    HR(const HR& other);

    HR& operator=(const HR& other);

    virtual ~HR() { delete[] _department; };

    void who() const override { std::cout << _name << " работает в отделе кадров\n"; }
    void show() const override;

   protected:
    char* _department;
};

class Engineer : public Administration {
   public:
    Engineer() : Administration(){};
    Engineer(const char* name, int salary, int category) : Administration(name, salary), _category(category){};
    Engineer(const Engineer& other) : Administration(other), _category(other._category){};
    virtual ~Engineer(){};

    void who() const override { std::cout << _name << " работает инженером\n"; }
    void show() const override;

   protected:
    int _category;
};
