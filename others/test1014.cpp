#include <iostream>
using namespace std;

class Point {
public:
	Point(int x = 0, int y = 0) :x(x),y(y){}
	int getX(){
		return x;

	}
private:
	int x;
	int y;
};
int main() {
	Point test1014;
	int a=test1014.getX();
	cout << "the number is : " << a << endl;
	return 0;

}
