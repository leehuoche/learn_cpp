#include"Point.h"
#include<iostream>
using namespace std;


Point::	Point (){
		x=y=0;
		cout<<"defaule constructor called"<<endl;
}

Point::	Point (int x,int y):x(x),y(y){
		cout<<"constructor called"<<endl;
}




Point::	~Point (){
		cout<<"destructor called"<<endl;
}



void Point::	move (int newX,int newY){
	cout<<"moving the point to ("<<newX<<","<<newY<<")"<<endl;
	x=newX;
	y=newY;
}



	void Point:: showCount(){
	//	cout<<"Object count="<<count<<endl;
	}
