#include <iostream>
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
private:
	int x,y;
};



int main(){
	Point a(4,5);
	Point *p1=&a;
	cout<<p1->getX()<<endl;
	cout<<a.getX()<<endl;
	
	return 0;
}