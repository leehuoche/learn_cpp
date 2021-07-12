#include <string>
#include <iostream>
#include <array>
using namespace std;



class Time {
	int hours;
	int minutes;
	int num;
public:
	int GetHour() {
		return hours;
	}
	void Showstep() {
		//int a = GetHour();
		cout <<num << ":(x,y)=" << "(" << hours << "," << minutes << endl;
	}
	Time operator+(const Time& a)const{}
	Time operator-(const Time& a)const {}
	Time operator*(const Time& a)const {}
	friend Time operator*(double x,const Time& a){}
	friend Time operator+(double x,const Time& a){}
	
};

class Stonewt {
	int stone;
	double pds_left;
	double pounds;
	int type;
public:
	void operator<<(Stonewt& a) const{

	}
	Stonewt operator+(const Stonewt& a) {
		Stonewt k;
		k.stone = a.stone + stone;
		return k;
	}
	bool operator< (const Stonewt& a);

};



class complex {
	int real;
	int vir;
public:
	complex() {

	}
	complex(int r, int v) {

	}
	~complex()
	{

	}

	complex operator+(const complex& a) {	}
	complex operator-(const complex& a) {	}
	complex operator*(const complex& a) {	}
	complex operator/(const complex& a) {	}
	//complex operator() {	}

	friend ostream& operator<<(ostream os,const complex& a){
		os << a.real << a.vir << endl;
		return os;
	}
	//complex operator>>() {}

};


int main11() {
	Time a;
	a.Showstep();
	return 0;
}