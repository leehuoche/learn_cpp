#include <iostream>
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





int main(){
	Point *ptr=new Point[2];
	ptr[0].move(5,10);
	ptr[1].move(15,20);
	cout<<"deleting..."<<endl;
	delete []ptr;
	return 0;
}
	