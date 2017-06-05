#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
struct A{
	int num;
	char name;
	char sex;
	int age;
};

int main(){
	A stu={97001,'g','F',19};
	cout<<"num is"<<stu.num<<endl;
	cout<<"name is "<<stu.name<<endl;
	return 0;
}
