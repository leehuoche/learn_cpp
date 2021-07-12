#include <iostream>
#include "tp131.h"
using namespace std;




#include <cstring>

// baseDMA methods
baseDMA::baseDMA(const char* l, int r)
{
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

baseDMA::baseDMA(const baseDMA& rs)
{
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}

baseDMA::~baseDMA()
{
    delete[] label;
}

baseDMA& baseDMA::operator=(const baseDMA& rs)
{
    if (this == &rs)
        return *this;
    delete[] label;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

//std::ostream& operator<<(std::ostream& os, const baseDMA& rs)
//{
//    os << "Label: " << rs.label << std::endl;
//    os << "Rating: " << rs.rating << std::endl;
//    return os;
//}

// lacksDMA methods
lacksDMA::lacksDMA(const char* c, const char* l, int r)
   /* : baseDMA(l, r)*/
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char* c, const baseDMA& rs)
    /*: baseDMA(rs)*/
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

//std::ostream& operator<<(std::ostream& os, const lacksDMA& ls)
//{
//    os << (const baseDMA&)ls;
//    os << "Color: " << ls.color << std::endl;
//    return os;
//}

// hasDMA methods
hasDMA::hasDMA(const char* s, const char* l, int r)
   /* : baseDMA(l, r)*/
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char* s, const baseDMA& rs)
    /*: baseDMA(rs)*/
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA& hs)
    /*: baseDMA(hs)*/  // invoke base class copy constructor
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete[] style;
}

hasDMA& hasDMA::operator=(const hasDMA& hs)
{
    if (this == &hs)
        return *this;
    //baseDMA::operator=(hs);  // copy base portion
    delete[] style;         // prepare for new style
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}

//std::ostream& operator<<(std::ostream& os, const hasDMA& hs)
//{
//    os << (const baseDMA&)hs;
//    os << "Style: " << hs.style << std::endl;
//    return os;
//}



















void Bravo(const Cd& disk);

int testcd()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
        "Alfred Brendel", "Philips", 2, 57.17);
    Cd* pcd = &c1;

    cout << "Using object directly: \n";
    c1.Report();
    c2.Report();

    cout << "Using type cd * pointer to objects: \n";
    pcd->Report();
    pcd = &c2;
    pcd->Report();

    cout << "Calling a function with a Cd reference argument: \n";
    Bravo(c1);
    Bravo(c2);

    cout << "Testing assignment: ";
    Classic copy;
    copy = c2;
    copy.Report();

    return 0;
}

void Bravo(const Cd& disk)
{
    disk.Report();
}


int main132() {
    Bacvir* tt[5];
    baseDMA a;
    lacksDMA b;
    hasDMA c;

    tt[0] = &a;
    tt[1] = &b;
    tt[2] = &c;

    for (int i = 0; i < 3; i++) {
        tt[i]->show();
    }
    return 0;
}