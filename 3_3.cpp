#include <iostream>
using namespace std;
double arctan(double x){
	double sqr=x*x,e=x,r=0;
	int i=1;
	while(e/i>1e-15){
		double f=e/i;
		r=(i%4==1)?r+f:r-f;
		e=e*sqr;
		i+=2;
	}
	return r;
}
	
int main(){
	double PI=16.0*arctan(1/5.0)-4.0*arctan(1/239.0);
	cout<<PI<<endl;
}