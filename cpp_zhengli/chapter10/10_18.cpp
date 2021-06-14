#include <iostream>
#include<functional>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
bool g(int x, int y) {
	return x > y;
}
int main() {
	int arr[] = { 1,3,2,4,5,29,6 };
	const int N = 7;
	vector<int> a(arr, arr + N);
	vector<int>::iterator p ;
	p = find_if(a.begin(), a.end(), bind2nd(not2(greater<int>()),10));
	cout << "answer is " << *p << endl;
	
	return 0;
}