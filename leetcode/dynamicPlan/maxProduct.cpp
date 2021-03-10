/*
* 子数组的最大乘积
*/
class Solution {
public:
    double maxProduct(vector<double> arr) {
        if (arr.empty()) return 0.0;
        int len = arr.size();
        
        vector<double> f(len, 0);  // 存储之前的最大值数组
        vector<double> g(len, 0);  // 存储最小值数组, 最大值有可能是两个最小值乘积而来
        f[0] = arr[0];
        g[0] = arr[0];
        double curMax = arr[0];  // 存储最大值
        for (int i = 1; i < len; ++i)
        {
            f[i] = max(max(f[i - 1]* arr[i], g[i - 1]* arr[i]), arr[i]);
            g[i] = min(min(f[i - 1]* arr[i], g[i - 1]* arr[i]), arr[i]);
            curMax = max(curMax, f[i]);
        }
        return curMax;
    }
};
