//
// Created by looperX on 2019-10-19.
//
#include <memory>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct AreBothSpaces
{
    // override
    bool operator()(char x, char y)
    {
        return x == ' ' && y == ' ';
    }
};

int main()
{
    string str = "a   bb  ccc  dddd";
    auto last = std::unique(str.begin(),str.end(), AreBothSpaces());
    str.erase(last, str.end());
    std::cout << str << std::endl;
}

