#include <iostream>
using namespace std;
int 	getvolume(int length,int width=2,int height=3);
int main(){
	const int x=10,y=12,z=15;
	cout<<"xyz is";
	getvolume(x,y,z);
	cout<<"xy is";
	getvolume(x,y);
	cout<<"x is";
	getvolume(x);
	return 0;
}
int 	getvolume(int length,int width,int height){
	cout<<"----- "<<length<<"----- "<<width<<"----- "<<height<<endl;
	return 0;
}

