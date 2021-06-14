#include <string>
#include <iostream>
using namespace std;
void test(const char*title,bool value){
	cout<<title<<"returns  "<<(value?"true":"false")<<endl;
}

int main(){
	string s1="DEF";
	cout<<"s1 is "<<s1<<endl;

	string s2;
	cout<<"please enter s2 ";
	cin>>s2;


	test("s1<=\"ABC\"",s1<="ABC");
	s2+=s1;
	cout<<"s2+=s1  "<<s2<<endl;
	cout<<"length of s2: "<<s2.length()<<endl;
	return 0;
}