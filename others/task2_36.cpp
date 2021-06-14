#include <iostream>
using namespace std;
int main(){
	const N=9;
	int i,j;
	for(j=1;j<=N;j++){
		for(i=1;i<=j;i++)
			cout<<i<<"*"<<j<<"="<<i*j<<' ';
		cout<<endl;
	}
	return 0;
}
