#include <iostream>
using namespace std;
int main(){
	int a[5]={1,2,3,4,5};//int *p=a;
	for(int *p=a;p<(a+4);p++)
		cout<<*p<<" ";
	cout<<endl;

	cout<<*(p)<<"------------";
	cout<<endl;
	return 0;
}
