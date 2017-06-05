#include <iostream>
using namespace std;
class Point{
public:
	Point(int xx=0,int yy=0){
		x=xx;
		y=yy;
		count++;
	}
	Point (Point &p){
		x=p.x;
		y=p.y;
		count++;
	}

	~Point(){count--;}
	int getX(){
		return x;
	}
	int getY(){
		return y;
	}
	void showCount(){
		cout<<"Object count="<<count<<endl;
	}
	static int count;
private:
	int x,y;
	
};

int Point::count=0;

int main(){
	int *ptr=&Point::count;
	Point a(4,5);
	cout<<"Point a:"<<a.getX()<<","<<a.getY()<<endl;
	cout<<"object count="<<*ptr<<endl;
	Point b(a);
	cout<<"Point b:"<<b.getX()<<","<<b.getY()<<endl;
	cout<<"object count="<<*ptr<<endl;
	return 0;
}
	



















