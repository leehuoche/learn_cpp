#include <iostream>
#include<functional>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
int main() {
	ostream_iterator<int>output(cout, "¡¡");
	int iarray[] = { 26,17,15,22,23,33,32,40 };
	vector<int> ivector(iarray, iarray + sizeof(iarray) / sizeof(int));
	
	vector<int> ivector1(5);
	sort(ivector.begin(), ivector.end());
	cout << binary_search(ivector.begin(), ivector.end(),33) << endl;
	//copy(ivector1.begin(), ivector1.end(), output);
	//cout << *p << endl;


}