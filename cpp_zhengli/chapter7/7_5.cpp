#include <iostream>
using namespace std;

class Base1 {
public:
	//Base1() { cout << "default base1" << endl; }
	Base1(int i) { cout << "base1 display     " << i << endl; }
	~Base1() { cout << "delete base1" << endl; }
};
class Base2 :public Base1 {
public:
	//Base2() { cout << "default base2" << endl; }
	Base2(int j) { cout << "base2 display      " << j << endl; }
	~Base2() { cout << "delete base2" << endl; }
};
class Base3 :public Base2 {
public:
	Base3() { cout << "base3 display" << endl; }
	~Base3() { cout << "delete base3" << endl; }
};
class Derived :public Base2, public Base1, public Base3 {
public:
	Derived(int a, int b, int c, int d) :Base1(a), member2(d), member1(c), Base2(b) {
		cout << "derived is construed" << endl;
	}
private:
	Base1 member1;
	Base2 member2;
	Base3 member3;
};


int main() {

	Derived obj(1, 2, 3, 4);
	return 0;

}