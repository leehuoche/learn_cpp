#include <iostream>
using namespace std;
#include<string>

int main() {
	string line;
	cout << "type a line terminated t" << endl;
	getline(cin, line, 't');
	cout << line << endl;

		return 0;
	
}