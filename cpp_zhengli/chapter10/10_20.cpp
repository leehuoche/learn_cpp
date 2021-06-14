#include <iostream>
#include<functional>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
int main() {
	int iarray[] = { 0,1,2,3,4,5,6,6,6,7,8 };
	vector<int> ivector(iarray, iarray + sizeof(iarray) / sizeof(int));
	int iarray1[] = { 0,1,2,3,9 };
	vector<int> ivector1(iarray1, iarray1 + sizeof(iarray1) / sizeof(int));

	//cout << *adjacent_find(ivector.begin(), ivector.end()) << endl;
	//cout << count_if(ivector.begin(), ivector.end(),bind2nd(less<int>(),7)) << endl;
	//cout << *find_if(ivector.begin(), ivector.end(), bind2nd(greater<int>(), 2)) << endl;
	//cout << *search(ivector.begin(), ivector.end(), ivector1.begin(), ivector1.end()) << endl;
	//cout << *search_n(ivector.begin(), ivector.end(), 3,6,equal_to<int>()) << endl;
	//cout <<equal(ivector.begin(), ivector.end(), ivector1.begin()) << endl;
	pair<vector<int>::iterator, vector<int>::iterator> result;
	result= mismatch(ivector.begin(), ivector.end(), ivector1.begin()) ;
	cout << *result.first;
		return 0;
}