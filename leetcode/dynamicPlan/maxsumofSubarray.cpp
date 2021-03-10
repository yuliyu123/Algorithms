class Solution {
public:
    /**
     * max sum of the subarray
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxsumofSubarray(vector<int>& arr) {
        // write code here
        int result = INT_MIN;  // 存sum变化之前的值，因为sum可能会变小
        int sum = 0;
        
        for (int i = 0; i < arr.size(); ++i)
        {
            sum = std::max(sum + arr[i], arr[i]);
            result = std::max(result, sum);  // sum变化之前的值跟最新的sum值比较，取最大
        }
        return result;
    }
};
