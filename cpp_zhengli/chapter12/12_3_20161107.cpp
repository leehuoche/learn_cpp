#include <iostream>
#include<cmath>
#include<stdexcept>
using namespace std;

double area(double a, double b, double c)throw(invalid_argument) {
	if (a <= 0 || b <= 0 || c <= 0)
		throw invalid_argument("the side should be positive");
	if (a + b <= c || b + c <= a || a + c <= b)
		throw invalid_argument("the side is not fit");
	double s = (a + b + c) / 2;
	return sqrt(s*(s - a)*(s - b)*(s - c));
}
int main() {
	double a, b, c;
	cout << "input the side :  ";
	cin >> a >> b >> c;
	try {
		double s = area(a, b, c);
		cout << "area   " << s << endl;

	}
	catch(exception &e){
		cout << "error;  " << e.what() << endl;

	}
	return 0;
}
