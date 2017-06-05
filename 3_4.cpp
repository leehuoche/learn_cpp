#include <iostream>
using namespace std;
bool symm(unsigned n){
	unsigned i=n,m=0;
	while(i>0){
		m=m*10+i%10;
		i/=10;
	}
	return m==n;
}
int main(){
	for(unsigned m=2;m<1003;m++){
		if(symm(m)&&symm(m*m))
			cout<<"m="<<m<<endl;
	}
	return 0;
}