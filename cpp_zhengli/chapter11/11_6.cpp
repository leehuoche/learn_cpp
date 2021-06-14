#include<sstream>
#include<string>
#include <iostream>
using namespace std;


template<class T>
string toString(const T&v) {
	ostringstream os;
	os << v;
	return os.str();
}

int main() {
	string str1 = toString(5);
	cout << str1<< endl;
	return 0;

}
