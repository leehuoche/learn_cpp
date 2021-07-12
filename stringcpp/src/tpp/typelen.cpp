
#include <string>
#include <iostream>
#include <array>
using namespace std;

struct Tfish {
	string type;
	int weight;
	float len;
};

void decalare() {
	array<char,30> actor;
	array<short,100> be;
	char aa[] = { "chessburege" };
	struct Tfish f1 = { "f1",10,2.4 };
	Tfish* ptr = new Tfish;
	ptr->weight = 19;

	Tfish ar[3];
	Tfish* p3 = new Tfish[3];

	int* t = nullptr;
	delete [] t;

	//delete [] p3;

	int m = sizeof(p3);



	cout << (int*)"hello" << endl;
	cout << endl;
}



int tt3() {
	char ch;
	int ct1, ct2;
	ct1 = ct2 = 0;
	while ((ch=cin.get())!='$')
	{
 		cout << ch;
		ct1++;
		if (ch = '$')
			ct2++;
		cout << ch;
	}
	cout << "ct1=" << ct1 << ",ct2=" << ct2 << endl;
	return 0;
}

#include <fstream>
void ReadFile() {
	ifstream rr;
	char filename[4];
	rr.open(filename);
	int count=0;
	while (!rr.eof())
	{
		count++;
	}
	rr.close();

}

void ttclear();

void WriteFile() {
	ofstream out;
	char filename[4];
	out.open(filename);
	out << "is end";
	out.close();
	//ttclear();
}


template< typename T>
void Swap(T& a,T& b) {
	cout << a << endl;
}


template<> void Swap(Tfish& a, Tfish& b) {

}


template void Swap<int>(int & a,int &b);




void pf81(char* addr,int a=0) {

}

void pf81(const Tfish& a,const char* b="Med",double c=2.0,int d=350) {

}

void pf83(const string& ss) {
	for(auto a:ss)
		cout << toupper(a);
}


template<typename T>
T max5(T a[],int len) {
	return a[0];
}

template<> char* max5(char* a[],int len) {
	return NULL;
}



class BankCount {
private:
	char name[128];
	char count[128];
	int num;
public:
	BankCount():num(0) {
		cout << "default constructor" << endl;
	}
	BankCount(const char* n,const char* c,int n1) {
		strcpy(name, n);
		strcpy(count, c);
		num = n1;
	}
	~BankCount(){
		cout << "deconstruct bank count" << endl;
	}
	void set(char* n, char* c, int n1){
		strcpy(name, n);
		strcpy(count, c);
		num = n1;
	}
	void show() const{
		cout << name << ":" << count << ":" << num << endl;
	}
	void conserver(int n) {
		num += n;
	}
	int get(int n) {
		num -= n;
		return num;
	}
	const BankCount& add() {
		return *this;
	}
};

void ShowBankCount() {
	BankCount a1;

	a1.set((char*)"yy", (char*)"xx", 100);
	a1.show();
	a1.conserver(25);
	a1.show();
	a1.get(13);
	a1.show();
	BankCount b1 = a1.add();

}



class Person {
private:
	static const int LIMIT = 25;
	string lname;
	char fname[LIMIT];
public:
	Person() { lname = ""; fname[0] = '\0'; }
	Person(const string& ln, const char* fn = "heyyou") {
		lname = ln;
		strcpy(fname,fn);
	}
	void Show()const {
		cout << fname <<":"<< lname << endl;
	}
	void FormalShow()const {
		cout << lname << "," << fname << endl;
	}
};

void testPerson() {
	Person one;
	Person two("Sym");
	Person three("Da","sam");
	one.Show();
	one.FormalShow();
	two.Show();
	two.FormalShow();
	three.Show();
	three.FormalShow();
	
}


class Golf {
	const static int len = 40;
	char fullname[len];
	int handicap;
public:
	Golf() {
		
	}
	~Golf()
	{

	}

	Golf(const char* name,int hc) {
		strcpy(fullname, name);
		handicap = hc;
	}

	/*Golf(Golf& g) {

	}*/

	void handicap1(int hc) {

	}

	void showGolf() const {

	}

};



namespace SALES {

	class Sales {
		double sales[4];
		double average;
		double max;
		double min;
	public:
		Sales() {

		}
		Sales(Sales& s, const double ar[], int n) {

		}

	};

}


class Plorg {
	char name[19];
	int ci;
public:
	void SetCi(int c) {
		ci = c;
	}
	void Show()const {
		cout << name << ":" << ci << endl;
	}
	Plorg(int c, char* n = (char*)"Plorga") {
		ci = c;
		strcpy(name, n);
	}
	Plorg(){}
};
Plorg a;

int main44() {
	cout <<"int:"<< sizeof(int) << endl;
	cout << "double:" << sizeof(double) << endl;

	int a = 30;
	double b = 45.1;
	a = static_cast<int> (b);
	//decalare();
	//tt3();
	//ShowBankCount();
	testPerson();
	return 0;
}