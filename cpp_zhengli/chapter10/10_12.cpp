#include<map>
#include<utility>
#include<iterator>
#include <iostream>
#include<string>
using namespace std;

int main() {
	multimap<string, int>course;
	typedef multimap<string, int>::iterator CourseIter;

	course.insert(make_pair("COM", 13));
	course.insert(make_pair("C++", 42));
	course.insert(make_pair("COM", 34));
	course.insert(make_pair("OS", 22));
	course.insert(make_pair("OS", 3));
	course.insert(make_pair("OS", 2));
	string name;
	int count;
	do
	{
		cin >> name;
		count = course.count(name);

	} while (count==0);
	cout << count << " lessons per week";
	pair<CourseIter, CourseIter>range = course.equal_range(name);
	for (CourseIter iter = range.first; iter != range.second; ++iter)
		cout << iter->second << " ";
	cout << endl;
	return 0;


}