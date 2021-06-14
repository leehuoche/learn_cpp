#include <iostream>
#include<functional>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
int main() {
	int arr[] = { 1,3,2,4,5,29,6  };
	const int N = 7;
	vector<int> a(arr, arr + N);
	vector<int>::iterator p = find_if(a.begin(), a.end(), bind2nd(greater<int>(), 20));
	cout << "answer is " << *p << endl;
	/*cout << "before :" << endl;
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, "\t "));
	cout << endl;
	sort(a.begin(), a.end(), greater<int>());
	cout<<"after:" << endl;
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, "\t "));
	cout << endl;*/
	return 0;
}