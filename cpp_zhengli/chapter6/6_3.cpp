#include"Point.h"
#include<iostream>
using namespace std;
int main(){
	cout<<"entering main..."<<endl;
	Point a[2];
	for(int i=0;i<2;i++)
		a[i].move(i+10,i+20);
	cout<<"exiting main..."<<endl;
	return 0;
}