#include "threadpool.h"

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <functional>
#include <stdio.h>
#include <memory>
#include <queue>

using namespace std;

class ThreadPool1
{
public:
    typedef function<void()> TaskFunc;

    ThreadPool1(int thread_num) : thread_num_(thread_num)
    {
        for (int i = 0; i < thread_num_; i++)
        {

            pool_.push_back(thread(bind(&ThreadPool1::RunInThread, this)));
        }
    }

    ThreadPool1(ThreadPool1 &a) = delete;
    ThreadPool1 &operator=(const ThreadPool1 &a) = delete;
    ~ThreadPool1()
    {
    }

    void Stop()
    {
        running = false;
        is_empty.notify_all();
        for (vector<thread>::iterator it = pool_.begin(); it != pool_.end(); it++)
        {
            it->join();
        }
    }

    void AddToPool(TaskFunc f)
    {
        int size = task_que.size();
        if (size >= thread_num_)
        {
            cout << " pool is full" << endl;
            return;
        }

        mtx.lock();
        task_que.push(f);
        is_empty.notify_one();
        mtx.unlock();
    }

    void RunInThread()
    {
        while (running)
        {
            unique_lock<mutex> lock(mtx);
            while (task_que.empty() && running)
            {
                is_empty.wait(lock);
            }
            TaskFunc task = task_que.front();
            task_que.pop();
            lock.unlock();

            task();
        }
    }

private:
    int thread_num_;
    vector<thread> pool_;
    condition_variable is_empty;

    mutex mtx;
    bool running;
    queue<TaskFunc> task_que;
};

int main()
{
}