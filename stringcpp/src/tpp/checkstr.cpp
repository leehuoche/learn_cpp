
#include <string>
#include <iostream>

using namespace std;

bool CheckLength(string& s) {
	int upper = 0;
	int lower = 0;
	int num = 0;
	int other = 0;

	int size = s.size();
	if (size > 10) {
		return true;
	}
	
	for (int i = 0; i < size; i++) {
		if (isupper(s[i])) { upper = 1; }
		else if (islower(s[i])) { lower = 1; }
		else if (isdigit(s[i])) { num = 1; }
		else { other = 1; }
	}

	int sum = upper + lower + other + num;

	if (num == 0 || num == 1) {
		return size >= 10;
	}
	else if (num == 3) {
		return size >= 8;
	}
	else if (num == 4) {
		return size >= 6;
	}
	else {
		return false;
	}
}


bool CheckReplica(string& s) {
	int size = s.size();
	for (int i = 1; i < size;i++) {
		string pt = s.substr(i-1,i+1);
		string left = s.substr(i + 1, size);
		if (left.find(pt) != string::npos) {
			return false;
		}
	}
	return true;
}


bool CheckSeq(string& s) {
	int size = s.size();
	
	for (int i = 2; i < size; i++) {
		if (isdigit(s[i-2]) && isdigit(s[i - 1]) && isdigit(s[i])) {
			if (s[i] - s[i - 1] == 1 && s[i - 1] - s[i - 2] == 1) { return false; }
			if (s[i] - s[i - 1] == -1 && s[i - 1] - s[i - 2] == -1) { return false; }
		}

	}
	return true;
}


int GetString() {
	string s;
	int on_run = 1;
	while (on_run) {
		getline(cin,s);
		if (CheckLength(s)&& CheckReplica(s) && CheckSeq(s)) {
			cout << "OK" << endl;
		}
		else {
			cout << "NG" << endl;
		}
	}
	return 0;
}