#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;



int FindNum(vector<int>& a) {
	int size = a.size();
	if (size == 0)
		return INT_MAX;
	else if (size <=2)
		return a[0];

	sort(a.begin(), a.end());

	int left, right, mid, real;
	left = 0;
	right = size - 1;
	mid = 0;
	real = 0;

	if (a[0] + 1 < a[1])
		return a[0];


	while (left<right)
	{
		if (right - left == 1)
			return a[right];

		mid = (right - left) / 2 + left;
		real = a[0] + mid;
		if (a[mid] == real)
			left = mid;
		else if (a[mid] < real)
			right--;
	}
	return INT_MAX;
}


void TestFind() {
	vector<int> a = { 1, 3, 2, 3 };
	vector<int> a1 = { 2, 5, 3, 7, 4 };
	vector<int> a2 = { 1,2, 5, 3, 1, 4 };
	vector<int> a3 = { 1,2, 5, 3, -3, 4 };
	if (3 != FindNum(a)) {
		cout << "a error" << endl;
	}
	 if (7 != FindNum(a1)) {
		cout << "a1 error" << endl;
	}
	 if (1 != FindNum(a2)) {
		cout << "a2 error" << endl;
	}
	 if (-3 != FindNum(a3)) {
		 cout << "a3 error" << endl;
	 }
	cout << "right" << endl;
}





int strStr1(string haystack, string needle) {
	int hsize = haystack.size();
	int nsize = needle.size();

	if (nsize == 0) {
		return nsize;
	}

	if (hsize < nsize) { return -1; }

	int i = 0;
	int j = 0;


	for (i = 0; i < hsize; i++) {
		if (needle[0] == haystack[i]) {

			j = 0;
			bool is = false;
			while (j < nsize) {
				if (needle[j] == haystack[j + i])
					j++;
				else
					is = true;
				break;
			}
			if (j == nsize) { return i; }
		}

	}
	return -1;
}

int main() {
	//TestFind();
	strStr1("hello", "ll");
	return 0;
}