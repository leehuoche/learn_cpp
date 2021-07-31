

// pairs.cpp -- defining and using a Pair template
#include <iostream>
#include <string>


#include <list>
#include <algorithm>
#include <vector>
#include <valarray>

using namespace std;
template <class T1, class T2>
class Pair
{
private:
    T1 a;
    T2 b;
public:
    T1& first();
    T2& second();
    T1 first() const { return a; }
    T2 second() const { return b; }
    Pair(const T1& aval, const T2& bval) : a(aval), b(bval) { }
    Pair() {}
};

template<class T1, class T2>
T1& Pair<T1, T2>::first()
{
    return a;
}
template<class T1, class T2>
T2& Pair<T1, T2>::second()
{
    return b;
}



//class Wine {
//    typedef valarray<int> ArrayInt;
//    typedef Pair<ArrayInt, ArrayInt> PairArray;
//private:
//    string label;
//    PairArray tt;
//    int year;
//public:
//    Wine(const char* l, int y, const int yr[], const int bot[]) :
//        tt(ArrayInt(yr, y), ArrayInt(bot, y))
//    {
//        label=l;
//        year = y;
//    }
//    Wine(const char* l, int y): tt(ArrayInt( y), ArrayInt( y) ){
//        label = l;
//        year = y;
//        
//    }
//    int GetBottles() {
//        int y, b;  // year, bottle
//
//        std::cout << "Enter " << label << " data for " << year << " year(s)" << std::endl;
//        for (int i = 0; i < year; ++i)
//        {
//            std::cout << "Enter year:";
//            std::cin >> y;
//            tt.first()[i] = y;
//            std::cout << "Enter bottles for that year: ";
//            std::cin >> b;
//            tt.second()[i] = b;
//        }
//        return 0;
//    }
//    string& Label() {
//        return label;
//    }
//    int sum() {
//        return tt.second().sum();
//    }
//    void Show()const {
//        std::cout << "Wine: " << label << std::endl;
//        std::cout << "Year  " << "  Bottles" << std::endl;
//        for (int i = 0; i < year; ++i)
//        {
//            std::cout << tt.second()[i] << "    ";
//            std::cout << tt.first()[i] << std::endl;
//        }
//    }
//};


typedef valarray<int> ArrayInt;
class Wine: public Pair<ArrayInt, ArrayInt>,public string{
    int year;
public:
    Wine(const char* l, int y, const int yr[], const int bot[]):
    string(l),
    year(y),
    Pair(ArrayInt(yr,y),ArrayInt(bot,y))
    {

    }

    Wine(const char* l, int y):
    string(l),
    year(y),
    Pair(ArrayInt(y),ArrayInt(y))
    {

    }

    int GetBottles() {
          int y, b;  // year, bottle

        std::cout << "Enter " << (string&)*this << " data for " << year << " year(s)" << std::endl;
        for (int i = 0; i < year; ++i)
        {
            std::cout << "Enter year:";
            std::cin >> y;
            Pair::first()[i] = y;
            std::cout << "Enter bottles for that year: ";
            std::cin >> b;
            Pair::second()[i] = b;
        }
        return 0;
    }
    string& Label() {
        return *this;
    }
    int sum() {
        return Pair::second().sum();
    }
    void Show()const {
        std::cout << "Wine: " << (string&)*this << std::endl;
        std::cout << "Year  " << "  Bottles" << std::endl;
        for (int i = 0; i < year; ++i)
        {
            std::cout << Pair::second()[i] << "    ";
            std::cout << Pair::first()[i] << std::endl;
        }
    }

};

int testWine()
{
    using std::cout;
    using std::cin;
    using std::endl;

    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab, 50);
    cout << "Enter number of years: ";
    int yrs;
    cin >> yrs;

    Wine holding(lab, yrs);
    holding.GetBottles();
    holding.Show();

    const int YRS = 3;
    int y[YRS] = { 1993, 1995, 1998 };
    int b[YRS] = { 48, 60, 72 };
    Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();
    cout << "Total bottles for " << more.Label()
        << ": " << more.sum() << endl;
    cout << "Bye\n";

    return 0;
}












// workmi.cpp -- multiple inheritance
// compile with workermi.cpp
#include <iostream>
#include <cstring>




class Worker   // an abstract base class
{
private:
    std::string fullname;
    long id;
protected:
    virtual void Data() const;
    virtual void Get();
public:
    Worker() : fullname("no one"), id(0L) {}
    Worker(const std::string& s, long n)
        : fullname(s), id(n) {}
    virtual ~Worker() ; // pure virtual function
    virtual void Set() {
        cout << "Enter worker's name: ";
        getline(cin, fullname);
        cout << "Enter worker's ID: ";
        cin >> id;
        while (cin.get() != '\n')
            continue;
    }
    virtual void Show() const 
    {
        cout << "Name: " << fullname << "\n";
        cout << "Employee ID: " << id << "\n";
    }
};



// Worker methods
Worker::~Worker() { }

// protected methods
void Worker::Data() const
{
    cout << "Name: " << fullname << endl;
    cout << "Employee ID: " << id << endl;
}

void Worker::Get()
{
    getline(cin, fullname);
    cout << "Enter worker's ID: ";
    cin >> id;
    while (cin.get() != '\n')
        continue;
}


template<typename T>
class QueueTp {
private:
    T data[16];
    int cur;
    int size;
public:
    QueueTp(int a) {
        size = a;
        cur = 0;
    }
    bool isempty() {
        return cur == 0;

    }
    bool enqueue(T& a) {
        data[cur++] = a;
        return true;
    }
    bool isfull() {
        return cur == size;
    }
    void dequeue(T& w) {
        data[cur--];
    }
    void Show()const {
        cout << cur << endl;
    }

};



const int SIZE = 5;

int testq()
{
    QueueTp<Worker> q(3);

    if (q.isempty())
        cout << "Queue is empty" << endl;

    cout << "add worker1 to queue..." << endl;
    Worker w1("shao", 1);
    q.enqueue(w1);

    cout << "add worker2 to queue..." << endl;
    Worker w2("zheng", 2);
    q.enqueue(w2);

    cout << "add worker3 to queue..." << endl;
    Worker w3("jiang", 3);
    q.enqueue(w3);

    if (q.isfull())
        cout << "queue is full" << endl;

    Worker w;
    cout << "delete worker1..." << endl;
    q.dequeue(w);
    w.Show();

    return 0;
}




class Person {
private:
    string first_name;
    string last_name;
public:
    Person(){}
    Person(string f, string l):first_name(f),last_name(l) {

    }
    void Show()const {
        cout << first_name << " " << last_name << endl;
    }
};

class Gunslinger :virtual public Person {
    int num;
    double t;
public:
    Gunslinger(){}
    Gunslinger(string f, string l, int n) :Person(f, l), num(n) {

    }
    double Draw() {
        t = 5;
        return t;
    }
    void Show()const {
        cout << num <<" "<<t<< endl;
    }
};




class PokerPlayer :virtual public Person {
    int card;
public:

    PokerPlayer(){}
    PokerPlayer(string f, string l, int n) :Person(f, l), card(n) {

    }
    int Draw() {
        return card;
    }
    void Show()const {
        Person::Show();
    }

};


class BadDude : public Gunslinger, public PokerPlayer {
public:
    BadDude(){}
    BadDude(string f, string l):Person(f,l),Gunslinger(f,l,5),PokerPlayer(f,l,6) {

    }
    int Gdraw() {
        return Gunslinger::Draw();
    }
    int Cdraw() {
        return PokerPlayer::Draw();
    }
    void Show()const {
        cout << " bad dude" << endl;
    }
};


int main147()
{
    using namespace std;
    int ct, i;
    Person* gang[SIZE];

    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the gang category: \n"
            << "o: ordinary person  g: gunslinger  "
            << "p: pokerplayer  b: bad dude  q: quit \n";
        cin >> choice;
        while (strchr("ogpbq", choice) == NULL)
        {
            cout << "Please enter an o, g, p, b, or q: ";
            cin >> choice;
        }

        if (choice == 'q')
            break;

        switch (choice)
        {
        case 'o': gang[ct] = new Person;
            break;
        case 'g': gang[ct] = new Gunslinger;
            break;
        case 'p': gang[ct] = new PokerPlayer;
            break;
        case 'b': gang[ct] = new BadDude;
            break;
        }

        cin.get();
        //gang[ct]->Set();
    }

    cout << "\nHere is your gang: \n";
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        gang[i]->Show();
    }
    for (i = 0; i < ct; i++)
        delete gang[i];
    cout << "Bye" << endl;

    return 0;
}