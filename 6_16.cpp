
//动态创建对象
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
	cout<<"step  one:"<<endl;
	Point *ptr1=new Point;
	delete ptr1;
	cout<<"step  two:"<<endl;
	Point *ptr2=new Point;
	delete ptr2;
	return 0;
}



