#include <iostream>
using namespace std;
int square(int a,int b){
	return a+b;
}
double square(double a,double b){
	return a+b;
}

int main(){
	int a,b;
	double x,y;
	cout<<" enter int a,b";
	cin>>a>>b;
	cout<<square(a,b);
	cout<<"enter double x,y";
	cin>>x>>y;
	cout<<square(x,y);
	return 0;
}
