#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class Count {
public:
    vector<int> date;
    bool is_complete;
};


class TodoSystem {
private:
    map<string, Count> tasks;
public:
    TodoSystem()

    {
    }

    int AddTask(int startDate, string content, int num, int period)
    {
        auto t = tasks.find(content);
        if (t == tasks.end()) {
            //insert
            Count* new_count=new Count();
            vector<int>& new_num=new_count->date;
            new_count->is_complete = false;
            for (int i = 0; i < num; i++) {
                new_num.push_back(startDate + period * i);
            }
            tasks.insert(pair<string, Count>(content, *new_count));
            return num;
        }
        else {
            int ans = num;
            Count& s = t->second;
            vector<int>& content_second = s.date;
            for (int j = 0; j < num; j++) {
                auto it = find(content_second.begin(), content_second.end(), startDate + j * period);
                if (it == content_second.end()) {
                    content_second.push_back(startDate + j * period);
                }
                else {
                    ans--;
                }
            }
            return ans;

        }

    }

    bool FinishTask(int date, string content)
    {
        auto t = tasks.find(content);
        if (t == tasks.end()) {
            return false;
        }
        else {
            Count& s = t->second;
            vector<int>& content_second = s.date;
            auto it = find(content_second.begin(), content_second.end(), date);
            if (it != content_second.end()) {
                return false;
            }
            else {
                s.is_complete = true;
                return true;
            }
        }

    }

    bool RemoveTask(int date, string content) {
        auto t = tasks.find(content);
        if (t == tasks.end()) {
            return false;
        }

        Count& s = t->second;
        vector<int>& content_second = s.date;
        auto it = find(content_second.begin(), content_second.end(), date);
        if (it != content_second.end()) {
            content_second.erase(it);
            return true;
        }
        else {
            return false;
        }
    }
};