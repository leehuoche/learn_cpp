#include <iostream>
using namespace std;
void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
int main(){
	int x=5,y=10;
	cout<<x<<"___________"<<y<<endl;
	swap(x,y);
	cout<<x<<"___________"<<y<<endl;
	return 0;
}
