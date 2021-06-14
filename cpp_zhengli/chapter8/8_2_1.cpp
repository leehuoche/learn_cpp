#include <iostream>
using namespace std;
class Clock {
public:
	
    Clock(int newH = 0, int newM = 0, int newS = 0);
	void showTime();
	Clock &operator++();
	Clock operator++(int);
private:
	int hour, minute, second;
};

 Clock::Clock(int newH, int newM, int newS) {
	hour = newH;
	minute = newM;
	second = newS;
}

void Clock::showTime() {
	cout << hour << ":" << minute << ":" << second << endl;
}
Clock &Clock::operator++() {
	second++;
	if (second >= 60) {
		second -= 60;
		minute++;
		if (minute >= 60) {
			minute -= 60;
			hour = (hour + 1) % 24;
		}
	}
	return *this;
}



Clock Clock::operator++(int) {
	Clock old = *this;
	++(*this);
	return old;
}

int main() {
	Clock myClock(23, 59, 59);
	cout << "first time is:";
	myClock.showTime();
	cout << "(myClock++ is";
	(myClock++).showTime();
	cout << "(++myClock) is";
	(++myClock).showTime();
	return 0;


}