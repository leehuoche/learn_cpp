#include <iostream>
using namespace std;
#include<string>
class MyException
{
public:
	MyException(const string &message):message(message){}
	~MyException(){}
	const string &getMessgae()const { return message; }

private:
	string message;

};
class Demo
{
public:
	Demo(){
		cout <<"constructor of Demo" << endl;
	}
	~Demo(){
		cout << "Destructor of Demo" << endl;
	}
};
	void fun() throw(MyException) {
		Demo d;
		cout << "throw MyException in fun" << endl;
		throw MyException("exception thrown by func()");
	}





int main() {
	cout << "in the main function" << endl;
	 
	try {
		fun();
	}
	catch(MyException & e) {

	cout << "caught an exception "<<e.getMessgae() << endl;

	}
	cout << "resume the execution of main" << endl;

	return 0;

}
