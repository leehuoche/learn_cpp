#include <iostream>
using namespace std;
//虚函数的意义在于可以调用派生类的函数
class Base1 {
public:
	virtual void display() const { cout << "base1 display" << endl; }
};
class Base2 :public Base1 {
public:
	void display() const { cout << "base2 display" << endl; }
};
class Derived :public Base2 {
public:
	void display() const { cout << "derived display" << endl; }
};
void fun(Base1 *ptr) {
	ptr->display();
}
int main() {
	Base1 base1;
	Base2 base2;
	Derived derived;
	fun(&base1);
	fun(&base2);
	fun(&derived);
	return 0;
}