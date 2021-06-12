
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
// use string constructor
void string_constructor() {

	

	string one("lottery winner");
	cout << one << endl;
	string two(20, '$');

	string three(one);
	cout <<two << three << endl;
	one += " ops";
	cout << one << endl;

	two = " that was";
	three[0] = 'P';

	string four;
	four = two + three;
	cout << four << endl;

	char alls[] = " all is well,that ends well";
	string five(alls, 20);
	cout << five << endl;

	string six(alls + 6, alls + 10);
	cout << six << ',';
	string seven(&five[6], &five[10]);
	cout << seven << "...\n"<< "five is a object,so it is not ptr"<<endl;

	string eight(four, 7, 16);
	cout << eight << endl;
	



}


int read_file() {

	ifstream fin;
	fin.open("tobuy.txt");

	if (fin.is_open() == false) {
		cerr << "open fail" << endl;
		exit(EXIT_FAILURE);
	}

	string item;
	int count = 0;
	getline(fin, item, ';');
	while (fin) {
		++count;
		cout << count << ";" << item << endl;
		getline(fin, item,';');
	}

	cout << " Done\n";
	fin.close();
	return 0;

}

int main() {
	//string_constructor();
	read_file();
	return 0;
}