#include<set>
#include<utility>
#include<iterator>
#include <iostream>
using namespace std;

int main() {
	set<double> s;
	while (true)
	{
		double v;
		cin >> v;
		if (v == 0) break;
		pair<set<double>::iterator, bool> r = s.insert(v);
		if (!r.second)
			cout << v << "is duplicated" << endl;


	}
	set<double>::iterator iter1 = s.begin();
	set<double>::iterator iter2 = s.end();
	double medium = (*iter1 + *(--iter2)) / 2;
	cout << "<=medium:";
	copy(s.begin(), s.upper_bound(medium), ostream_iterator<double>(cout, " "));
	cout << endl;
	cout << ">=medium:";
	copy(s.lower_bound(medium), s.end(), ostream_iterator<double>(cout, " "));
	cout << endl;
	return 0;
}