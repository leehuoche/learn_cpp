#include <iostream>
#include<iterator>
#include<list>
#include<deque>
using namespace std;
template<class T>
void printContainer(const char*msg, const T &s) {
	cout << msg << ": ";
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

}
int main() {
	deque<int>s;
	int a[10] = { 1,4,2,6,33,67,3,4,11,9 };
	for (int i = 0; i < 10; i++) 		
		s.push_front(a[i]);
	
	printContainer("deque at first", s);

	list<int> l(s.rbegin(), s.rend());
	printContainer("list at first", l);

	list<int>::iterator iter = l.begin();
	while (iter!=l.end())
	{
		int v = *iter;
		iter = l.erase(iter);
		l.insert(++iter, v);

		
	}
	printContainer("list at last", l);

	s.assign(l.begin(), l.end());
	printContainer("deque at last", s);


	return 0;
}