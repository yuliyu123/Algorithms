/*
 * The same instance of Foo will be passed to three different threads.
 * Thread A will call first(), thread B will call second(), and thread C will call third().
 * Design a mechanism and modify the program to ensure that second() is executed after first(),
 * and third() is executed after second().
 * */

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <unordered_map>
#include <vector>
#include <condition_variable>

using namespace std;

class Foo
{
    mutex m;
    condition_variable cv;
    volatile int counter = 0;
public:
    Foo() {

    }

    void first(function<void()> printFirst)
    {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        counter++;
        cv.notify_all();
    }

    void second(function<void()> printSecond)
    {
        unique_lock<mutex> l(m);
        cv.wait(l, [&]{ return counter == 1;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        counter++;
        cv.notify_all();
    }

    void third(function<void()> printThird)
    {
        unique_lock<mutex> l(m);
        cv.wait(l, [&]{ return counter == 2;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};


int main()
{

}
