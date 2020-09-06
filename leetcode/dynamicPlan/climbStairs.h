//
// Created by looperX on 2020-09-03.
//

#ifndef ALGORITHMMS_CLIMBSTAIRS_H
#define ALGORITHMMS_CLIMBSTAIRS_H


class Solution {
public:
    int climbStairs(int n) {

        if (n == 1) return 1;
        if (n == 2) return 2;

        std::vector<int> dp;
        dp.resize(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i-2];
        }
        return dp[n];
    }
};

#endif //ALGORITHMMS_CLIMBSTAIRS_H
