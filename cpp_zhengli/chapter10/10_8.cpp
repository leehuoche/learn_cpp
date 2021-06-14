// 10_8.cpp : 定义控制台应用程序的入口点。
#include<queue>
#include<cstdlib>
#include<ctime>
#include <iostream>
using namespace std;

const int SPLIT_TIME_MIN = 500;

const int SPLIT_TIME_MAX = 2000;
priority_queue<Cell> cellQueue;

class Cell {
	static int count;
	int id;
	int time;
public:
	Cell(int birth) :id(count++) {
		time = birth + (rand() % (SPLIT_TIME_MAX - SPLIT_TIME_MIN) + SPLIT_TIME_MIN);
	}
	int getId()const { return id; }
	int getSplitTime()const { return time; }
	bool operator<(const Cell&s)const { return time < s.time; }
	void split() {
		Cell child1(time), child2(time);
		cout << time << "s:Cell#" << id << "splits to #" << child1.getId() << " and #" << child2.getId() << endl;
		cellQueue.push(child1);
		cellQueue.push(child2);

	}
};
int Cell::count = 0;

int main(){
	srand(static_cast<unsigned>(time(0)));
	int t;
	cout << "simulation time:";
	cin >> t;
	cellQueue.push(Cell(0));
	while (cellQueue.top().getSplitTime() <= t) {
		cellQueue.top().split();
		cellQueue.pop();
	}
    return 0;
}

