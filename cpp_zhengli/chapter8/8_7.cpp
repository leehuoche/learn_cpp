#include"Trapzint.h"
#include <iostream>
using namespace std;
#include<iomanip>

int main() {
	MyFunction f;
	Trapz trapz(f);
	cout << "TRAPZ Int:" << setprecision(7) << trapz(0, 2, 1e-7) << endl;
	return 0;
}