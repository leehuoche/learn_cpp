#include<cctype>
#include<map>
#include <iostream>
using namespace std;
int main() {
	map<char, int>s;
	char c;
	do
	{
		cin >> c;
		if (isalpha(c)) {
			c = tolower(c);
			s[c]++;
		}
	} while (c!='.');
	for (map<char, int>::iterator iter = s.begin(); iter != s.end(); ++iter)
		cout << iter->first << "¡¡" << iter->second << "¡¡";
	cout << endl;
	return 0;
}