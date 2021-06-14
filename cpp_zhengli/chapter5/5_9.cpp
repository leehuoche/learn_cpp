#include <iostream>
#include<cmath>
using namespace std;

class Point{
public:
	Point(int xx=0,int yy=0){
		x=xx;
		y=yy;
	}
	int getX(){
		return x;
	}

	int getY(){
		return y;
	}
	friend double dist(const Point &p1,const Point &p2);
private:
	int x,y;
};


double dist(const Point &p1,const Point &p2){
	double x=p1.x-p2.x;
	double y=p1.y-p2.y;
	return (sqrt(x*x+y*y));
}

	

int main(){
	const Point myp1(1,1),myp2(4,5);
	cout<<"the dist is ";
	cout<<dist(myp1,myp2)<<endl;
	return 0;
}