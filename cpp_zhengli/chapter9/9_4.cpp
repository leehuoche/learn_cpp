#include<iomanip>
#include"Array.h"
#include <iostream>
using namespace std;

int main() {
	Array<int> a(10);
	int count = 0;
	int n;
	cout << "enter a value>=2 as upper limit for prime numbers: ";
	cin >> n;

	for (int i = 2; i <= n; i++) {
		bool isPrime = true;
		for (int j = 0; j < count;j++)
			if (i%a[j] == 0) {
				isPrime = false;
				break;
			}
		if (isPrime) {
			if (count == a.getsize())
				a.resize(count * 2);
			a[count++] = i;

		}
	}

	for (int i = 0; i < count; i++)
		cout << setw(8) << a[i];
	cout << endl;

	return 0;




}