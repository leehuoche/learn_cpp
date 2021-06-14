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
	ArrayOfPoint(const ArrayOfPoint &v){
		size=v.size;
		points=new Point[size];
		for(int i=0;i<=size;i++)
			points[i]=v.points[i];
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
	ArrayOfPoint pointsArray1(count);
	pointsArray1.element(0).move(5,0);
	pointsArray1.element(1).move(15,20);

	ArrayOfPoint pointsArray2= pointsArray1;
	cout<<"copy of pointsArray1:"<<endl;
	cout<<"Point_0 of array2:"<<pointsArray2.element(0).getX()<<","
		<<pointsArray2.element(0).getY()<<endl;
	cout<<"Point_1 of array2:"<<pointsArray2.element(1).getX()<<","
		<<pointsArray2.element(1).getY()<<endl;

	pointsArray1.element(0).move(25,30);
	pointsArray1.element(1).move(35,40);
	cout<<"after the moving of pointsarray1:"<<endl;
	cout<<"Point_0 of array2:"<<pointsArray2.element(0).getX()<<","
		<<pointsArray2.element(0).getY()<<endl;
	cout<<"Point_1 of array2:"<<pointsArray2.element(1).getX()<<","
		<<pointsArray2.element(1).getY()<<endl;





	return 0;
}


