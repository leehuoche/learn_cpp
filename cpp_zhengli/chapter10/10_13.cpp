#include<numeric>
#include <iostream>
#include<functional>
using namespace std;

int mult(int x, int y) { return x*y; }
int main() {
	int a[] = { 1,2,3,4,5 };
	const int N = 5;
	cout << accumulate(a, a + N, 1, multiplies<int>()) << endl;
	return 0;
}
