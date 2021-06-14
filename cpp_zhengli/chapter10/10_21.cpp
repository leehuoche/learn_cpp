#include <iostream>
#include<functional>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
class evenByTwo
{
public:
	evenByTwo() :x(0) {}

	int operator()() { return x += 2; }

private:
	int x;

};

int main() {
	int iarray1[] = { 0,1,2,3,4,4,5,5,6,6,6,6,6,7,8 };
	int iarray2[] = { 0,1,2,3,4,5,6,6,6,7,8 };
	vector<int> ivector1(iarray1, iarray1 + sizeof(iarray1) / sizeof(int));
	vector<int> ivector2(iarray2, iarray2 + sizeof(iarray2) / sizeof(int));
	vector<int> ivector3(2);
	vector<int> ivector4;
	ostream_iterator<int>output(cout, "¡¡");
	//ivector2.erase(remove_if(ivector2.begin(), ivector2.end(),bind2nd(less<int>(),6 )),ivector2.end());
	rotate_copy(ivector2.begin(), ivector2.begin()+3, ivector2.end(),output);
	//copy(ivector2.begin(), ivector2.end(), output);
	cout << endl;

	return 0;
}