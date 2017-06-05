
//这是函数指针  也就是指向函数的指针的声明及初始化
#include <iostream>
using namespace std;
void printStuff(float){
	cout<<"this is the print stuff function"<<endl;
}
void printMessage(float data){
	cout<<"the data to be listed is "<<data<<endl;
}
void printFloat(float data){
	cout<<"the data to be listed is "<<data<<endl;
}
const float PI=3.1415;
const float TWOPI=PI*2;
int main(){
	void(*functionPointer)(float);
	printStuff(PI);
	functionPointer=printStuff;
	functionPointer(PI);
	functionPointer=printMessage;
	functionPointer(TWOPI);
	functionPointer=printFloat;
	functionPointer(PI);
	return 0;
}
