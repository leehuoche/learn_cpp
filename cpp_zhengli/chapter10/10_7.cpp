#include<stack>
#include<iostream>
using namespace std;
int main() {
	stack<char>s;
	string str = { "congratulations" };
	for (string::iterator iter = str.begin(); iter != str.end(); ++iter) {
		s.push(*iter);
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << endl;
	return 0;
}