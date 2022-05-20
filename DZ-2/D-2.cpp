#include <iostream>
#include <string>

using namespace std;
//DZ-1=========================================
class Person
{
public:
    static int GetCount() { return count; }
    Person( string& name, int& age,string& gender,int& weight)
        : n_name(name), n_age(age), n_weight(weight), n_gender(gender)
    {
        n_age = (age > 0) ? age : 0;
        n_weight = (weight > 0) ? weight : 0;
        count++;
    }

    string GetName() { return n_name; }
    int GetAge() { return n_age; }
    int GetWighr() { return n_weight; }
    void Print()
    {
        cout << n_name << ' ' << n_age << ' ' << n_gender << ' ' << n_weight << endl;
        
    }
private:
    static int count;
protected:
    string n_name;
    int n_age;
    string n_gender;
    int n_weight;

};

class Student : public Person
{

public:
    Student(int year,  string& name, int age, string& gender,int weight)
        :Person(name, age, gender, weight), n_year(year)
    {
        n_year = (year > 0) ? year : 0;
    }
    int GetYear() { return n_year; }
    void AddYear(int addValue)
    {
        n_year += addValue;
    }
    void AddYear()
    {
        n_year++;
    }

    void Print()
    {
        
        cout << n_year << ' ';
        Person::Print();
    }
private:
    int n_year;
};
int Person::count = 0;
//=============================================

//DZ-2=========================================
class Fruit
{
public:
    Fruit(string name, string color)
        : name(name), color(color) {}
    string getName()
    {
        return name;
    }
    string getColor()
    {
        return color;
    }
    string name;
    string color;

};


class Banana : protected Fruit
{
public:
    Banana(string name = "Banana", string color = "Yellow")
        : Fruit(name, color){ }
    string getName()
    {
        return name;
    }
    string getColor()
    {
        return color;
    }
};


class Apple : protected Fruit
{
public:
    Apple(string color="Red", string name = "Apple")
        : Fruit(name, color) {}
    string getName()
    {
        return name;
    }
    string getColor()
    {
        return color;
    }
};


class GrannySmith : protected Apple
{
public:
    GrannySmith(string name = "Granny Smith", string color = "Green") 
        : Apple(color, name) {}
    string getName()
    {
        return name;
    }
    string getColor()
    {
        return color;
    }
};

//================================================================
int main()
{
    //DZ-1========================================================
    const int N = 2;
    Person* pers[N];
    for (int i = 0; i < N; i++)
    {
        int year, weight, age;
        string name, gender;
        cout << "Enter: name, age, gender, weight, year:" << endl;
        cin >> name >> age >> gender >> weight >> year;
        pers[i] = new Student(year, name, age, gender, weight);
        cout << "Count=" << pers[i]->GetCount() << endl;
    }

    for (int i = 0; i < N; i++)
        pers[i]->Print();

    Student* s1 = static_cast<Student*>(pers[0]);
    s1->AddYear(2);

    cout << "New age of " << s1->GetName() << " = "
        << s1->GetAge() << endl;

    for (int i = 0; i < N; i++)
        delete pers[i];
    //============================================================
    
    //DZ-2========================================================
    Apple a("red");
    Banana b;
    GrannySmith c;

    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
    //============================================================
    return 0;
}
//DZ-3============================================================
/*
#include<time.h>
using namespace std;
static int index = 1;
class Card
{
public:
    Card(int);
    ~Card();
    void Sort();
    int Rozd();
    int RozdBank();
    int Symma(int);
    int Symma();
    int SymmaBank(int);
    int SymmaBank();
private:

    int KolKart;
    int Mast[4];
    int* Dost;
    int* Kploda[4];
};

static int summa = 0;
static int summabank = 0;
Card::Card(int kol) {
    KolKart = kol;
    for (int i = 0; i < 4; i++) {
        Mast[i] = i + 3;
    }
    Dost = new int[kol / 4];
    for (int i = 0; i < (kol / 4); i++) {
        Dost[i] = (kol / 4 == 13) ? i + 2 : i + 6;
    }

    for (int i = 0; i < 4; i++) {
        Kploda[i] = new int[kol / 4];
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < (kol / 4); j++) {
            Kploda[i][j] = 0;
        }
    }
}
Card::~Card() {
    delete[]Dost;
    for (int i = 0; i < 4; i++)
        delete[]Kploda[i];
}
void Card::Sort() {
    int m, n;
    for (int karta = 1; karta <= KolKart; karta++) {
        m = rand() % 4;
        n = rand() % 13;
        while (Kploda[m][n] != 0) {
            m = rand() % 4;
            n = rand() % 13;
        }
        Kploda[m][n] = karta;
    }
}
int Card::Rozd() {
    int a;
    for (int j = 0; j <= 3; j++) {
        for (int k = 0; k <= 12; k++) {
            if (Kploda[j][k] == index) {
                cout << " " << (char)Mast[j] << " - ";
                a = Dost[k];
                if (Dost[k] <= 10)
                    cout << Dost[k] << endl;
                else {
                    switch (Dost[k]) {
                    case 11:
                        cout << "J" << endl;
                        break;
                    case 12:
                        cout << "Q" << endl;
                        break;
                    case 13:
                        cout << "K" << endl;
                        break;
                    case 14:
                        cout << "A" << endl;
                        break;
                    }
                }
            }
        }
    }
    Symma(a);
    index++;
    return 0;
}
int Card::Symma(int a) {

    if (a <= 10)
        return summa += a;
    else if (a == 14)
        return summa += 11;
    else
        return summa += 10;
}
int Card::Symma() {
    return summa;
}
int Card::RozdBank() {
    int a;
    for (int j = 0; j <= 3; j++) {
        for (int k = 0; k <= 12; k++) {
            if (Kploda[j][k] == index) {
                cout << " " << (char)Mast[j] << " - ";
                a = Dost[k];
                if (Dost[k] <= 10)
                    cout << Dost[k] << endl;
                else {
                    switch (Dost[k]) {
                    case 11:
                        cout << "J" << endl;
                        break;
                    case 12:
                        cout << "Q" << endl;
                        break;
                    case 13:
                        cout << "K" << endl;
                        break;
                    case 14:
                        cout << "A" << endl;
                        break;
                    }
                }
            }
        }
    }
    SymmaBank(a);
    index++;
    return 0;
}
int Card::SymmaBank(int a) {

    if (a <= 10)
        return summabank += a;
    else if (a == 14)
        return summabank += 11;
    else
        return summabank += 10;
}
int Card::SymmaBank() {
    return summabank;
}
void main() {
    srand((unsigned)time(NULL));
    Card A(52);
    A.Sort();
    cout << "Igrok\n";
    for (int i = 1; i <= 2; i++)
        A.Rozd();
    cout << "Summa = " << A.Symma() << endl;
    cout << "Bank\n";
    A.RozdBank();
    do {
        if (A.Symma() < 21) {
            cout << "Vzat kartu (1) Stop (0) __ ";
            cin >> index;
            if (index) {
                cout << "Igrok\n";
                A.Rozd();
                cout << "Summa = " << A.Symma() << endl;
                if (A.Symma() == 21) {
                    cout << "BLECK JACK\n";
                }
                else if (A.Symma() > 21) {
                    cout << "Perebor\n";
                    cout << "POBEDIL BANCK\n";
                }
            }
            else {
                do {
                    cout << "Bank\n";
                    A.RozdBank();
                    if (A.SymmaBank() == 21) {
                        cout << "Summa Banka = " << A.SymmaBank() << endl;
                        cout << "BLECK JACK\n";
                    }
                    else if (A.SymmaBank() > 21) {
                        cout << "Banck Perebor\n";
                        cout << "Summa Banka = " << A.SymmaBank() << endl;
                        cout << "POBEDIL IGROK\n";
                    }
                    else
                        cout << "Summa Banka = " << A.SymmaBank() << endl;
                } while (A.SymmaBank() < 17);
            }
        }
    } while (index && A.Symma() < 21);

    if (A.Symma() <= 21 && A.Symma() > A.SymmaBank())
        cout << "POBEDIL IGROK\n";
    if (A.SymmaBank() <= 21 && A.SymmaBank() > A.Symma())
        cout << "POBEDIL BANCK\n";
    if (A.SymmaBank() <= 21 && A.Symma() <= 21 && A.SymmaBank() == A.Symma())
        cout << "ROVNO\n";
}
*/