//
// Created by loohan on 2019/3/8.
//

#ifndef ALGORITHMMS_UTIL_H
#define ALGORITHMMS_UTIL_H
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> vec)
{
    for_each(vec.begin(), vec.end(), [&](int value)
    {
        std::cout << "value is: " << value << std::endl;
    });
}

template <typename T>
void printFunc(T arg)
{
    std::cout << arg << std::endl;
}

#endif //ALGORITHMMS_UTIL_H
