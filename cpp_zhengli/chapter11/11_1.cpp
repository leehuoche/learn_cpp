#include <iostream>
#include<string>
#include<iomanip>
using namespace std;


int main() {
	double values[] = { 1.23,35.36,653.7,4358.24 };
	string names[] = { "zoo","jimm","ai","stan" };
	for(int i = 0; i < 4; i++){
		
	
	cout <<setiosflags(ios_base::left)<<setw(6)<<names[i]<< setw(10)<< setiosflags(ios_base::scientific) <<values[i] << endl;
}
	return 0;
}