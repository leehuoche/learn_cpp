#include <iostream>
using namespace std;
double power(double x,int n){
	double val=1.0;
	while(n--)
		val*=x;
	return val;
}
int main(){
	cout<<"3 to power 2 is"<<power(3,2)<<endl;
	return 0;
}
