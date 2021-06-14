#include<map>
#include<utility>
#include<iterator>
#include <iostream>
#include<string>
using namespace std;

int main() {
	map<string, int>course;
	course.insert(make_pair("CSAPP", 3));
	course.insert(make_pair("C++", 2));
	int n = 2;
	int sum = 0;
	while (n > 0)
	{
		string name;
		cin >> name;
		map<string, int>::iterator iter = course.find(name);
		if (iter == course.end())
			cout << name << "is not available" << endl;
		else {
			sum += iter->second;
			course.erase(iter);
			n--;
		}
	}
	cout << "total credit " << sum << endl;
	return 0;
}