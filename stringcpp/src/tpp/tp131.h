#ifndef CLASSIC_H_
#define CLASSIC_H_

#include <iostream>

using namespace std;
// base class
class Cd
{
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;

public:
    Cd(const char* s1, const char* s2, int n, double x) {
        strcpy(performers, s1);
        strcpy(label, s2);
        selections = n;
        playtime = x;
    }
    Cd(){}
    Cd(const Cd& d) {
        strcpy(performers, d.performers);
        strcpy(label, d.label);
        selections = d.selections;
        playtime = d.playtime;
    }
    virtual ~Cd() { cout << "base deconstructor" << endl; };
    virtual void Report() const {
        printf("%s-%s-%d-%f\n",performers,label,selections,playtime);
    }
    Cd& operator = (const Cd& d) {
        if (this == &d)
            return *this;
        strcpy(performers, d.performers);
        strcpy(label, d.label);
        selections = d.selections;
        playtime = d.playtime;

        return *this;

    }
};


// derived class
class Classic : public Cd
{
private:
    char works[100];

public:
    Classic(const char* w, const char* s1, const char* s2, int n,
        double x) :Cd(s1, s2, n, x) {
        strcpy(works, w);
    }

    Classic(){}
    virtual ~Classic() { cout << "classic deconstructor" << endl; };
    virtual void Report() const {
        //printf("%s-%s-%d-%f\n", performers, label, selections, playtime);
        printf("%s-\n", works);
    }
};






class Bacvir {
public:
    virtual void show()const =0  ;
};





//  Base Class Using DMA
class baseDMA:public Bacvir
{
private:
    char* label;
    int rating;

public:
    baseDMA(const char* l = "null", int r = 0);
    baseDMA(const baseDMA& rs);
    virtual ~baseDMA();
    baseDMA& operator=(const baseDMA& rs);
    void show() const { cout << "baseDma" << endl; }
   /* friend std::ostream& operator<<(std::ostream& os,
        const baseDMA& rs);*/
};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA :public Bacvir
{
private:
    enum { COL_LEN = 40 };
    char color[COL_LEN];
public:
    lacksDMA(const char* c = "blank", const char* l = "null",
        int r = 0);
    lacksDMA(const char* c, const baseDMA& rs);
    void show() const { cout << "lacksDMA" << endl; }
   /* friend std::ostream& operator<<(std::ostream& os,
        const lacksDMA& rs);*/
};

// derived class with DMA
class hasDMA :public Bacvir
{
private:
    char* style;
public:
    hasDMA(const char* s = "none", const char* l = "null",
        int r = 0);
    hasDMA(const char* s, const baseDMA& rs);
    hasDMA(const hasDMA& hs);
    ~hasDMA();
    hasDMA& operator=(const hasDMA& rs);
    void show() const { cout << "hasDMA" << endl; }
    /*friend std::ostream& operator<<(std::ostream& os,
        const hasDMA& rs);*/
};







#endif