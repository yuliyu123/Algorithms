//
// Created by looperX on 2019-10-31.
//https://leetcode.com/problems/print-in-order/submissions/
//
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

class Foo {
private:
    volatile int count_ = 0; // disallow compiler to optimize count_
    std::mutex mtx_;
    std::condition_variable cv_;

public:

    Foo() {

    }

    void first(function<void()> printFirst) {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        count_++;
        cv_.notify_all(); // thread A notify all threads
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lk(mtx_);
        cv_.wait(lk, [&]() // thread B is notified.
        {
            return count_ == 1;
        });

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        count_++;
        cv_.notify_all(); // notify thread C
        lk.unlock();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lk(mtx_);
        cv_.wait(lk, [&]() // notify thread C
        {
            return count_ == 2;
        });

        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        lk.unlock();
    }
};

