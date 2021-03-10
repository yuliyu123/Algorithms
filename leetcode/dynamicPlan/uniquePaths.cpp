class Solution {
public:
    /**
     * 
     * @param m int整型 
     * @param n int整型 
     * @return int整型
     */
    int uniquePaths(int m, int n) {
        // write code here
        vector<vector<int> > dp(m, vector<int>(n, 1));  // 初始化整个矩阵为1，后期更改
        
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
