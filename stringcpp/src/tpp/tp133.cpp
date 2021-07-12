#include <cstring>
#include "tp133.h"
#include <iostream>

using namespace std;
/**************
 * Port methods
 **************/
Port::Port(const char* br, const char* st, int b)
{
    brand = new char[strlen(br) + 1];
    strcpy(brand, br);
    strcpy(style, st);
    bottles = b;
}

Port::Port(const Port& p)
{
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
}

void Port::Show() 
{
   /* cout << "Brand:" << brand << endl
        << "Kind:" << style << endl
        << "Bottles:" << bottles << endl;*/
   
}

// overloaded functions
Port& Port::operator=(const Port& p)
{
    if (this == &p)
        return *this;
    delete[] brand;
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
    return *this;
}

Port& Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

Port& Port::operator-=(int b)
{
    bottles -= b;
    return *this;
   
}

// friend functions
std::ostream& operator<<(std::ostream& os, const Port& p)
{
    os << p.brand << "," << p.style << "," << p.bottles << endl;
    return os;
}


/*********************
 * VintagePort methods
 *********************/

VintagePort::VintagePort(const char* br, int b, const char* nn, int y)
    : Port(br, "vintage", b)
{
    nickname = new char[strlen(nn) + 1];
    strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort& vp)
    : Port(vp)
{
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
   
}

void VintagePort::Show() const
{
    //Port::Show();
    cout << "year:" << year << endl
        << "nickname" << nickname << endl;
   
}

// overloaded functions
VintagePort& VintagePort::operator=(const VintagePort& vp)
{
    if (this == &vp)
        return *this;
    Port::operator=(vp);
    delete[] nickname;
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const VintagePort& vp)
{
    os << dynamic_cast<const Port&>( vp);
    os << "year" << vp.year << " nicename" << vp.nickname;
    return os;
}



int staticv::a = 0;


int main33t()
{


    staticv mm;
    mm.show();
    //staticv::a = 3;


    Port p1("rr","ee",12);
    Port p2("Tsingtao", "Beer", 30);
    VintagePort vp1("Harbin", 50, "hb", 1992);
    //p1 = vp1;

    //vp1 = p1;
    
    
    
    
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    Port p3 = p2;
    p3.Show();
    p3 += 3;
    p3.Show();

    //VintagePort vp1("Harbin", 50, "hb", 1992);
    vp1.Show();
    VintagePort vp2;
    vp2.Show();
    vp1 -= 3;
    vp2 = vp1;
    vp2.Show();

    return 0;
}