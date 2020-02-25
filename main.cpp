/*
<<<<<<< HEAD
=======
<<<<<<< Updated upstream
>>>>>>> origin/master
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

using namespace std;

class ZeroEvenOdd {
private:
    int n;
    int even_ = 0;
    int odd_ = 0;
    bool count_ = true;
    mutex mtx_;
    condition_variable cv_;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        unique_lock<mutex> lk(mtx_);
        for (int i = 0; i < n; i++)
        {
            cv_.wait(lk, [&]()
            {
                return count_ == true;
            });
            printNumber(0);
            count_ = false;
            cv_.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        unique_lock<mutex> lk(mtx_);
        for (int i = 2; i < n + 1; i += 2)
        {
            if ((i & 0x01) == 0) // is even. not need
            {
                cv_.wait(lk, [&]()
                {
                    return i == odd_ + 1 && count_ == false;
                });
                printNumber(i);
                even_ = i;
                count_ = true;
                cv_.notify_all();
            }
        }
    }

    void odd(function<void(int)> printNumber) {
        unique_lock<mutex> lk(mtx_);
        for (int i = 1; i < n + 1; i += 2)
        {
            if ((i & 0x01)) // is odd, not need
            {
                cv_.wait(lk, [&]()
                {
                    return i == even_ + 1 && count_ == false;
                });
                printNumber(i);
                odd_ = i;
                count_ = true;
                cv_.notify_all();
            }
        }
    }
};


int main()
{
    // 优先级： 先运算== 再算后面的
    int i = ((2 & 0x01) == 0);
    int j = (2 & 0x01 == 0);
    cout << i << endl;
    cout << j << endl;
}

