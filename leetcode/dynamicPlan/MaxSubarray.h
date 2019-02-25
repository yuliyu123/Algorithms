//
// Created by loohan on 2019/2/25.
//

#ifndef ALGORITHMMS_MAXSUBARRAY_H
#define ALGORITHMMS_MAXSUBARRAY_H

#include <iostream>
#include <climits>

/*
 * 思路：动态规划。 O(n), O(1)
 * 先求出某个位置之前的总和，再跟该位置做出比较，找出其中较大值。
 * 每个位置都这么比较，最后比较这些较大值的最大值
 * */
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int result = INT_MIN; // 最小负整数值
        int f = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            f = max(f + nums[i], nums[i]);
            result = max(result, f);
        }
        return result;
    }
};

#endif //ALGORITHMMS_MAXSUBARRAY_H
