//
// Created by looperX on 2020-08-24.
// 线程安全的单例模式
//

#ifndef ALGORITHMMS_SINGLESTON_H
#define ALGORITHMMS_SINGLESTON_H


#include <vector>
#include <iostream>
#include <mutex>

class SingleSton
{
public:
    SingleSton(const SingleSton& lhs) = delete;
    SingleSton operator=(const SingleSton& lhs) = delete;
    SingleSton(){ }
    static SingleSton* getInstance()
    {
        if (instance_ == nullptr)
        {
            // pseudo code, keep code safe, only have an object
            std::lock_guard<std::mutex> lock_guard(mtx_);
            if (instance_ == nullptr) {
                instance_ = new SingleSton();
            }
        }
        return instance_;
    }

private:
    static SingleSton* instance_;
    static std::mutex mtx_;
};


int main()
{
    const SingleSton* instance = SingleSton::getInstance();
}

#endif //ALGORITHMMS_SINGLESTON_H
