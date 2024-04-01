#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

using namespace std;

void countSentences() {
    /* Пользователь вводит два текста (две переменные).
     Вычислить количество предложений в каждом из них.*/

    string s1;
    string s2;
    getline(cin, s1);
    getline(cin, s2);

    cout << "Кол-во предложений в первом тексте: "
         << count(s1.begin(), s1.end(), '.') + count(s1.begin(), s1.end(), '!') + count(s1.begin(), s1.end(), '?')
         << '\n';
    cout << "Кол-во предложений в втором тексте: "
         << count(s2.begin(), s2.end(), '.') + count(s2.begin(), s2.end(), '!') + count(s2.begin(), s2.end(), '?')
         << '\n';
}

void deleteSpaces() {
    /*Пользователь вводит некоторую последовательность символов.
    Образовать новую последовательность, включив в нее символы исходной,
    кроме символов пробелов, точек и запятых.*/

    string str;
    getline(cin, str);
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    str.erase(remove(str.begin(), str.end(), '.'), str.end());
    str.erase(remove(str.begin(), str.end(), ','), str.end());
    cout << "Результат:" << str << '\n';
}

void readFromFileAndWrite() {
    /* Дан текстовый файл. Запишите в другой файл содержимое исходного файла,
    заменяя все маленькие латинские буквы на большие.*/

    string str;
    ifstream in("./test3.txt");
    if (in.is_open())
        getline(in, str);
    else
        cout << "Не удалось открыть файл\n";

    in.close();
    string res;
    for (auto ch : str) {
        if (islower(ch))
            res.push_back(toupper(ch));
        else
            res.push_back(ch);
    }

    ofstream out("./test3Res.txt");
    out << res;
    out.close();
}

template <class T>
void printVector(const vector<T> &vec) {
    for (const T &i : vec) cout << i << ' ';
    cout << '\n';
}

void manupulateVector() {
    /*
    Создайте вектор vector<float> и занесите в него 25 вещественных чисел в цикле for.
    Выведите содержимое вектора. Удалить из вектора элемент с индексом 1 и снова распечатать вектор.
    Переделать программу: печатать вектор с помощью функции.
    */

    vector<float> v;

    for (int i = 1; i <= 25; ++i) v.push_back((float)i / 3);
    printVector(v);
    v.erase(v.begin() + 1);
    printVector<float>(v);
}

template <class T>
void printList(const list<T> &lst) {
    for (const T &n : lst) cout << n << " ";
    cout << '\n';
}

class Point {
   public:
    double x, y;
    Point() { x = y = 0; }
    Point(double a, double b) : x(a), y(b){};
    double getDistance() const { return sqrt(x * x + y * y); };
    friend ostream &operator<<(ostream &out, const Point &p) { return out << '(' << p.x << ", " << p.y << ')'; }
    bool operator==(const Point &p2) const { return x == p2.x && y == p2.y; }
    bool operator<(const Point &p2) const { return getDistance() < p2.getDistance(); }
};

void printPoints(const vector<Point> &points, Point &farest) {
    for (auto p : points) {
        if (p.getDistance() > farest.getDistance()) farest = p;
        cout << p << '\n';
    }
}

void vectorPoints() {
    vector<Point> points = {{1.2, 6.3}, {4.0, 0.7}, {7.2, 0.8}, {5.3, 3.0}, {4.9, 6.6}, {9.3, 0.2}};
    Point farest;
    printPoints(points, farest);

    cout << "самая дальняя точка:" << farest << " расстояние = " << farest.getDistance() << '\n';
    int delta = 0;
    cout << "Введите на сколько сдвинуть по оси абцис: " << '\n';
    cin >> delta;

    for (Point &p : points) {
        p.x = p.x - delta;
    }

    printPoints(points, farest);
}

void manupulateList() {
    /*
    Описать функцию, которая добавляет после каждого элемента заданного контейнера-списка
    list<int> еще один такой же элемент, но с обратным знаком, а затем исключает из списка
    все отрицательные элементы и распечатывает результат.
    Переделать программу: печатать список до изменения и после с помощью функции.
    */

    list<int> lst{1, 2, -10, -12, 3, 4, 5};
    printList<int>(lst);

    std::list<int> result;

    for (int num : lst) {
        result.push_back(num);
        result.push_back(-num);
    }

    // lst = result;

    printList<int>(result);
    result.remove_if([](int a) { return a < 0; });
    printList<int>(result);
}

class Planet {
   public:
    string name;
    int numOfSatelites = 0;
};

void printList(list<Planet> lst) {
    for (Planet pl : lst) {
        cout << pl.name << '-' << pl.numOfSatelites << ' ';
    }
    cout << '\n';
}

void planetList() {
    list<Planet> lst = {{"Меркурий", 0}, {"Венера", 0}, {"Земля", 1}, {"Марс", 2}};
    lst.push_back({"Юпитер", 69});
    lst.push_back({"Сатурн", 62});
    lst.push_back({"Уран", 27});
    lst.push_back({"Нептун", 14});
    lst.push_back({"Плутон", 10});
    printList(lst);

    Planet max;
    for (Planet pl : lst) {
        if (pl.numOfSatelites > max.numOfSatelites) max = pl;
    }
    cout << "Максимальный элемент: " << max.name << '-' << max.numOfSatelites << '\n';
}

void manupMap() {
    /*
    Создайте отображение map<char, int> и занесите в него пары A-1, B-2, C-3, D-4, E-5.
    Выведите содержимое отображения на экран. Удалить пару с ключом C и снова распечатать отображение.
    */
    map<char, int> dict{
        {'A', 1},
        {'B', 2},
        {'C', 3},
        {'D', 4},
    };

    dict['E'] = 5;

    for (auto [ch, i] : dict) {
        cout << ch << '-' << i << '\n';
    }
    cout << '\n';
    dict.erase('C');
    for (auto [ch, i] : dict) {
        cout << ch << '-' << i << '\n';
    }
}

void printMap(map<string, int> dict) {
    for (auto it = dict.begin(); it != dict.end(); ++it) cout << it->first << '-' << it->second << '\n';
}

void states() {
    string states[] = {"Wyoming", "Colorado", "Nevada", "Montana", "Arizona", "Idaho"};
    int pops[] = {470, 2890, 800, 787, 2718, 944};

    /*
    На основе этих массивов создайте отображение, в котором ключ – это название американского штата,
    а значение – количество жителей этого штата в тысячах из массива pops.
    Напишите программу: пользователь вводит название штата,
    а в консоль выводится количество жителей этого штата.
    Выведите всё содержимое отображения в консоль с помощью функции.
    */

    map<string, int> dict;
    for (int i = 0; i < 6; i++) {
        dict[states[i]] = pops[i];
    }
    printMap(dict);
    // for (auto it = dict.begin(); it != dict.end(); ++it) cout << it->first << '-' << it->second << '\n';

    cout << '\n';
    string tmp;
    while (getline(cin, tmp)) {
        if (tmp == "0") break;
        cout << tmp << '-' << dict[tmp] << '\n';
    }
    printMap(dict);
}

int main() {
    /*--строки--*/
    // countSentences();  // 1
    // deleteSpaces();  // 2
    // readFromFileAndWrite();  // 3

    /*--векторы--*/
    // manupulateVector();  // 4
    // vectorPoints();  // 5(класс)

    /*--св списки--*/
    // manupulateList();  // 6
    // planetList();  //  7 (класс)

    /*--map--*/
    // manupMap();  // 8
    states();  // 9
    return 0;
}