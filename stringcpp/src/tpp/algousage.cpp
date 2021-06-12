
#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

void Show(int v) {
	cout << v << " ";
}

const int LIM = 10;
int listremove() {
	int ar[LIM] = { 4,5,4,2,2,3,4,8,1,4 };
	list<int> la(ar, ar + LIM);
	list<int> lb(la);

	cout << "originnal list\n";
	for_each(la.begin(), la.end(), Show);

	la.remove(4);
	cout << "\nla after .remove\n";
	for_each(la.begin(), la.end(), Show);

	list<int>::iterator last;
	last = remove(lb.begin(), lb.end(), 4);
	cout << "\nlb after function remove\n";
	for_each(lb.begin(), lb.end(), Show);

	lb.erase(last, lb.end());
	cout << "\nlb after .erase\n";
	for_each(lb.begin(), lb.end(), Show);
	return 0;
}



#include<set>
#include <map>
#include<iterator>


void display(const string& s) {
	cout << s << " ";
}

string& ToLower(string& st) {
	transform(st.begin(), st.end(), st.begin(), tolower);
	return st;
}


int usealgo() {
	vector<string> words;
	cout << " enter words \n";
	string input;
	while (cin>>input && input!="quit")
	{
		words.push_back(input);
	}
	cout << "you enter the following words\n";
	for_each(words.begin(), words.end(), display);


	set<string> wordset;
	transform(words.begin(), words.end(), insert_iterator<set<string> >(wordset, wordset.begin()), ToLower);

	cout << "\n list\n";
	for_each(wordset.begin(), wordset.end(), display);
	map<string, int> wordmap;
	set<string>::iterator si;
	for (si = wordset.begin(); si != wordset.end(); si++) {
		
		wordmap[*si] = count(words.begin(), words.end(), *si);
	}

	for (si = wordset.begin(); si != wordset.end(); si++) {
		cout << *si << ":" << wordmap[*si] << endl;
	}
	return 0;

}



#include <valarray>
#include <array>

void valvectro() {
	vector<double> data;
	double temp;

	cout << "enter num \n";
	while (cin>>temp && temp!=0)
	{
		data.push_back(temp);
	}
	sort(data.begin(), data.end());

	int size = data.size();
	valarray<double> numbers(size);
	int i;
	for (i = 0; i < size; i++) {
		numbers[i] = data[i];
	}

	valarray<double> sq_rts(size);
	sq_rts = sqrt(numbers);
	valarray<double> results(size);
	results = numbers + 2.0 * sq_rts;

	cout.setf(ios_base::fixed);
	cout.precision(4);

	for (i = 0; i < size; i++) {
		cout.width(8);
		cout << numbers[i] << ":";
		cout.width(8);
		cout << results[i] << endl;
	}
	cout << "done\n";
}

typedef valarray<int> vint;
void show(const vint& v,int cols) {
	int lim = v.size();
	for (int i = 0; i < lim; i++) {
		cout.width(3);
		cout << v[i];
		if (i % cols == cols - 1) {
			cout << endl;
		}
		else {
			cout << ' ';
		}
	}
	if (lim % cols != 0) {
		cout << endl;
	}
}

const int SIZE = 12;
void vslice() {
	vint valint(SIZE);

	int i;
	for (i = 0; i < SIZE; i++)
		valint[i] = rand() % 10;
	cout << "original\n";
	show(valint,3);

	vint vcol(valint[slice(1, 4, 3)]);
	cout << "2nd col\n";
	show(vcol, 1);

	vint vrow(valint[slice(3, 3, 1)]);
	cout << "2nd row\n";
	show(vrow, 3);



}


#include <initializer_list>
double sum(initializer_list<double> il) {
	double tot = 0;
	for (auto p = il.begin(); p != il.end(); p++) {
		tot += *p;
	}
	return tot;
}


void ilist() {
	cout << "list 1:sum= " << sum({ 2,3,4 });
	initializer_list<double> dl = { 1.1,2.2,3.3 };
	cout << "\n list 2:sum= " << sum(dl);
}

int main() {
	//listremove();
	//usealgo();
	//valvectro();
	//vslice();
	ilist();
}