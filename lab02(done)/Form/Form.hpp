#include <fstream>
// класс анкета для опроса населения
// частоты пользования общ траниспорта
// цифра сколько раз за месяц вы примерно пользовались типом транспорта

namespace form {
    class Form {
    private:
        char* name; // имя фамилия
        int bus;
        int subway;
        int tram;
        
    public:
        Form();
        Form(const char* newName, int diamiter, int life, int satelites);
        Form(const Form &p);
        ~Form();
        friend std::ostream & operator << (std::ostream& out, const Form& Form);
        friend std::istream & operator >> (std::istream& in,  Form& Form);
        friend bool operator< (const Form& Form1, const Form& Form2);
        friend bool operator> (const Form& Form1, const Form& Form2);
        friend bool operator== (const Form& Form1, const Form& Form2);
        Form& operator=(const Form& p2);
        char* getName();
        int getBus();
        int getSubway();
        int getTram();
        void setName(const char* newName);
        void setBus(int newBus);
        void setSubway(int newSubway);
        void setTram(int newTram);
    };

    int getForm(Form* arr, int& curSize, const char* targetName);
    void addObjToDB(Form* arr, int maxSize, int& curSize);
    void printDb(Form* arr, int n);
    void updateDb(Form* arr, int& curSize);
    void deleteByName(Form* arr, int& curSize);
    void sortByName(Form* arr, int curSize);
    int readDbFromFile(const char *filename, Form *arr, int &n);
    void writeDbToFile(const char *filename, Form* arr, int n);
}