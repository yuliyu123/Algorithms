class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;

        int low = prices[0], res = 0;

        for (int i = 1; i < prices.size(); ++i)
        {
            res = max(res, prices[i] - low);  // 更新最大值
            low = min(low, prices[i]);  // 更新最小值
        }

        return res;
    }
};
