
//虚基类：本质上是虚拟继承。作用：将不同方向继承来的“有相同名字的成员 ”只维护一个副本，避免混淆“这个成员”的定义域
#include <iostream>
using namespace std;
class Base0 {
public:
	Base0(int var):var0(var){}
	int var0;
	void fun0() {
		cout << "member of base0" << endl;
	}

};
class Base1 :virtual public Base0 {
public:
	Base1(int var):Base0(var){}
	int var1;

};
class Base2 :virtual public Base0 {
public:
	Base2(int var) :Base0(var) {}
	int var2;

};
class Derived :public Base1, public Base2 {
public:
	Derived (int var) :Base0(var),Base1(var),Base2(var) {}
	int var;
	void fun() {
		cout << "member of  Derived" << endl;
	}

};

int main() {
	Derived d(1);


	d.var = 2;
	d.fun();
	

	return 0;

}