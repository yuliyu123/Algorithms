/*
<<<<<<< Updated upstream
 * https://leetcode.com/problems/print-zero-even-odd/
 * */
#include <memory>
#include <iostream>
#include <ostream>
#include <string>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <functional>
#include <mutex>
#include <condition_variable>

using namespace std;

int main()
{
    // 优先级： 先运算== 再算后面的
    int i = ((2 & 0x01) == 0);
    int j = (2 & 0x01 == 0);
    cout << i << endl;
    cout << j << endl;
}

