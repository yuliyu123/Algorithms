//
// Created by loohan on 2019/2/25.
//

#ifndef ALGORITHMMS_COUNTOFONE_H
#define ALGORITHMMS_COUNTOFONE_H

#include <iostream>
#include <vector>

/*
 * 求整数数值转换为二进制中一的个数
 * O(n), O(1). 右移位减，左移位增
 * */
class Solution
{
public:
    int count(int input)
    {
        int count = 0;
        while (input)
        {
            if (input & 0x01)
                ++count;
            input >>= 1;
        }
        return count;
    }
};

#endif //ALGORITHMMS_COUNTOFONE_H
