//
// Created by loohan on 2019/2/25.
//

#ifndef ALGORITHMMS_MINIMUMTOTAL_H
#define ALGORITHMMS_MINIMUMTOTAL_H

// LeetCode, Triangle
// O(n^n) O(1)
/*
 * 状态转移方程：
 * f(i,j) 为状态， (i, j)为位置。
 * f(i,j) = min{f(i + 1,j),f(i + 1,j + 1)} + (i,j)
 * */

class Solution {
public:
    int minimumTotal (vector<vector<int>>& triangle) {
        for (int i = 0; i < triangle.size(); ++i )
        {

        }
    }
}
#endif //ALGORITHMMS_MINIMUMTOTAL_H
