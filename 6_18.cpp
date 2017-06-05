#include <iostream>
#include <cassert>
using namespace std;
class Point{
public:
	Point(){
		x=0;
		y=0;
		cout<<"calling the  default Constructor "<<endl;
	}
	Point( int xx, int yy){
		x=xx;
		y=yy;
		cout<<"calling the   Constructor "<<endl;
	}
	~Point(){	cout<<"calling the   DeConstructor "<<endl;
}


	int getX(){
		return x;
	}
	int getY(){
		return y;
	}
	void move(int newX,int newY){
		x=newX;
		y=newY;
	}

private:
	int x,y;
};



class ArrayOfPoint{
public:
	ArrayOfPoint(int size):size(size){
		points=new Point[size];
	}
	~ArrayOfPoint(){
		cout<<"deleting ..."<<endl;
		delete []points;
	}
	Point &element(int index){
		assert(index>=0&&index<=size);
		return points[index];
	}
	
private:
	Point *points;
	int size;
};


int main(){
	int count;
	cout<<"please enter the count of points";
	cin>>count;
	ArrayOfPoint points(count);
	points.element(0).move(5,0);
	points.element(1).move(15,20);
	return 0;
}