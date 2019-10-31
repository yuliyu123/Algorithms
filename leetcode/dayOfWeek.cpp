//
// Created by loohan on 2019/10/31.
//
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <unordered_map>
#include <vector>
#include <condition_variable>

using namespace std;
// 周几下面第几天
string dafOfWeek(string day, int k)
{
    vector<string> days = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
    unordered_map<string, int> daysMap;
    for (int i = 0; i < days.size(); ++i)
    {
        daysMap[days[i]] = i;
    }

    int dest = (k + daysMap[day]) % 7;
    return days[dest];
}

int main()
{
    cout << dafOfWeek("tuesday", 3);
}

