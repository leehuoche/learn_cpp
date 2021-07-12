//
//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//
//queue<int> msg_queue;
//mutext   mtx;
//
//void publish() {
//	int on_run = 1;
//	while (on_run) {
//		int a = 2;
//		pthread_lock(mtx);
//		msg_queue.push(a++);
//		pthread_unlock(mtx);
//	}
//}
//
//void sub() {
//	int on_run = 1;
//	while (on_run)
//	{
//		int ans = 0;
//		pthread_lock(mtx);
//		ans = msg_queue.front();
//		msg_queue.pop();
//		pthread_unlock(mtx);
//	}
//}
//
//int main() {
//	cout << "start" << endl;
//	pthread_init(mtx);
//
//	//pthread_create(thread_id,publish,arg1);
//	//pthread_create(thread_id2,sub,arg2);
//	while (true)
//	{
//		sleep(10);
//	}
//
//
//
//}