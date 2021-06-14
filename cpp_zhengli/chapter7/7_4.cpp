#include <iostream>
using namespace std;

class Base1 {
public:
	Base1(){}
	Base1(int i) { cout << "base1 display     " << i<<endl; }
};
class Base2 :public Base1 {
public:
	Base2(){}
	Base2(int j) { cout << "base2 display      " << j << endl; }
};
class Base3 :public Base2 {
public:
	Base3() { cout << "base3 display"  << endl; }
};
class Derived :public Base3 , public Base1, public Base2 {
public:
	Derived(int a ,int b,int c,int d):Base1(a),member2(d),member1(c),Base2(b){
		cout << "derived is construed" << endl;
	}
private:
	
	Base2 member2;
	Base1 member1;
	Base3 member3;
};


int main() {

	Derived obj(111, 222, 3, 4);
	return 0;

}