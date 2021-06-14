#include <iostream>
using namespace std;
#include<sstream>
#include<string>


template <class T>
T fromString(const string &str) {
	istringstream is(str);
	T v;
	is >> v;
	return v;

}
int main() {
	int v1 = fromString<int>("5");
	cout << v1 << endl;
	double v2 = fromString<double>("1.2");
	cout << v2 << endl;
	cout << v2+v1 << endl;

	return 0;
}