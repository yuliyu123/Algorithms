//
// Created by loohan on 2019/2/25.
//

#ifndef ALGORITHMMS_MAXPROFIT_02_H
#define ALGORITHMMS_MAXPROFIT_02_H

/*
 * Best Time to Buy and Sell Stock II
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
 * */

// 贪心算法。 O(n), O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            int diff = prices[i] - prices[i - 1];
            if (diff > 0) sum += diff; // 求正收益
        }
        return sum;
    }
};
#endif //ALGORITHMMS_MAXPROFIT_02_H
