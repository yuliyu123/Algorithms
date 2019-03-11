//
// Created by loohan on 2019/3/11.
//

#ifndef ALGORITHMMS_MAXESTSUBARR_H
#define ALGORITHMMS_MAXESTSUBARR_H

#include "Common.h"

int maxSubArray(vector<int> vec)
{
    int sum = 0;
    for_each(vec.begin(), vec.end(), [&](int iter)
    {
        sum += iter;
        if (sum < 0)
        {
            sum = 0;
        }
    });
    return sum;
}

//int main()
//{
//    vector<int> vec = {1, -2, -7, 8};
//    std::cout << maxSubArray(vec) << std::endl;
//    return 0;
//}

#endif //ALGORITHMMS_MAXESTSUBARR_H
