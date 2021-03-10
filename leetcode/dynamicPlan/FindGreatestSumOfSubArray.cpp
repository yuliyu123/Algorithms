class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int len = array.size();
        int res = INT_MIN;
        int tmp = 0;
        
        for (int i = 0; i < len; ++i)
        {
            tmp = std::max(tmp + array[i], array[i]);
            res = std::max(tmp, res);
        }

        return res;
    }
};
