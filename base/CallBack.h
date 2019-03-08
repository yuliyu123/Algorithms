//
// Created by loohan on 2019/3/8.
//

#ifndef ALGORITHMMS_CALLBACK_H
#define ALGORITHMMS_CALLBACK_H

#include <iostream>
#include <functional>

typedef std::function<void(int)> Callback;

void callback(int input)
{
    std::cout << "here is callback, input: " << input << std::endl;
}

void setCallBack(Callback cb, int i)
{
    cb(i);
    std::cout << "here is setCallBack" << std::endl;
    cb(++i);
}

#endif //ALGORITHMMS_CALLBACK_H
