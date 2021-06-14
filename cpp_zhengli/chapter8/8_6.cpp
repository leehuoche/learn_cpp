#include <iostream>
using namespace std;
//纯虚函数的意义在于提供调用派生类的函数的公共接口
class Base1 {
public:
	virtual void display() const = 0;
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
	
	Base2 base2;
	Derived derived;
	
	fun(&base2);
	fun(&derived);
	return 0;
}