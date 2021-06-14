#include <iostream>
using namespace std;
const float PI=3.141593,FENCE_PRICE=35,CONCRETE_PRICE=20;
class Circle{
public:
	Circle(float r);
	float circumference();
	float area();
private:
	float radius;
};

Circle::Circle(float r){
	radius=r;
}

float Circle::circumference(){
	return 2*PI*radius;
}
float Circle::area(){
	return PI*radius*radius;
}



int main(){
	float radius;
	cout<<"enter the radius of the pool:";
	cin>>radius;
	Circle pool(radius);
	Circle poolRim(radius+3);

	float fenceCost=poolRim.circumference()*FENCE_PRICE;
	cout<<"fenceing cost is $"<<fenceCost<<endl;
	return 0;
}