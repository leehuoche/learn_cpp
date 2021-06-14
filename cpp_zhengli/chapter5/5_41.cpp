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
private:
	int x,y;
	static int count;
};

//int Point::count=0;  这个程序是错误的




int main(){
	Point a(4,5);
	a.showCount();

	Point 	b=a;
	a.showCount();

	
	return 0;
}