//
// Created by loohan on 2019/3/11.
//

#ifndef ALGORITHMMS_LENMOREHALF_H
#define ALGORITHMMS_LENMOREHALF_H

#include "Common.h"

void moreHalf(vector<int> arr)
{
    int result = arr[0];
    int count = 1;

    for_each(arr.begin(), arr.end(), [&](int iter)
    {
        if (count == 0)
        {
            result = iter;
        }
        if (result == iter)
        {
            ++count;
        }
        else
        {
            --count;
        }
    });
    std::cout << "result is: " << result << std::endl;
}

#endif //ALGORITHMMS_LENMOREHALF_H
