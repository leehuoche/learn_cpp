#include <iostream>
using namespace std;
class Clock{
public:
	void setTime(int newH=0,int newM=0,int newS=0);
	void showTime();
private:
	int hour,minute,second;
};

void Clock::setTime(int newH,int newM,int newS){
	hour=newH;
	minute=newM;
	second=newS;
}

inline void Clock::showTime(){
	cout<<hour<<":"<<minute<<":"<<second<<endl;
}



Clock globClock;

int main(){

	cout<<"first time  output:"<<endl;
	globClock.showTime();
	globClock.setTime(8,30,30);




	Clock myClock(globClock);
	cout<<"second time  output:"<<endl;
	myClock.showTime();
	return 0;
}