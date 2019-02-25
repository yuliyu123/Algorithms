//
// Created by loohan on 2019/2/25.
//

#ifndef ALGORITHMMS_MAXPROFITS_H
#define ALGORITHMMS_MAXPROFITS_H

/*
 * Best Time to Buy and Sell Stock
 * 低进高出，找出收益最大那天的价格。低价的那天要小于高价的那天，天数不能小于2
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
 * */

// 贪心算法。 O(n), O(1)
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;

        int profit = 0;  // 当前收益为0
        int cur_min = prices[0];  // 当前最低价格

        for (int i = 0; i < prices.size(); ++i) {
            profit = max(profit, prices[i] - cur_min); // 更新收益
            cur_min = min(cur_min, prices[i]);  // 更新较低位价格
        }
        return profit;
    }
};

#endif //ALGORITHMMS_MAXPROFITS_H
