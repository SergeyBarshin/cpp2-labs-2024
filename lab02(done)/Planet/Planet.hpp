#include <fstream>

namespace planet {
    class Planet {
        private:
            char* name;
            int diamiter;
            int life;
            int satelites;
            
        public:
            Planet();
            Planet(const char* newName, int diamiter, int life, int satelites);
            Planet(const Planet &p);
            ~Planet();
            friend std::ostream & operator << (std::ostream& out, const Planet& planet);
            friend std::istream & operator >> (std::istream& in,  Planet& planet);
            friend bool operator< (const Planet& planet1, const Planet& planet2);
            friend bool operator> (const Planet& planet1, const Planet& planet2);
            friend bool operator== (const Planet& planet1, const Planet& planet2);
            Planet& operator=(const Planet& p2);
            char* getName();
            int getDiamiter();
            int getLife();
            int getSatelites();
            void setName(const char* newName);
            void setDiamiter(int newDiamiter);
            void setLife(int newLife);
            void setSatelites(int newSatelites);
    };

    int getPlanet(Planet* arr, int& curSize, const char* targetName);

    void addObjToDB(Planet* arr, int maxSize, int& curSize, const char* name, int diamiter, int life, int satelites);

    void printDb(Planet* arr, int n);

    void updateDb(Planet* arr, int& curSize, const char* targetName, const char* name, int diamiter, int life, int satelites);

    void deleteByName(Planet* arr, int& curSize, const char* targetName);

    void sortByName(Planet* arr, int curSize);

    int readDbFromFile(const char *filename, Planet *arr, int &n);

    void writeDbToFile(const char *filename, Planet* arr, int n);

}