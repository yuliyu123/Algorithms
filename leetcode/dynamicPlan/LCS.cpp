class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    string LCS(string s1, string s2) {
        // write code here
        int len1 = s1.size(), len2 = s2.size();
        string res = "";
        
        for (int i = 0; i < s1.length(); ++i)
        {
            for (int j = 0; j < s2.length(); ++j)
            {
                if (s1[i] == s2[j])
                {
                    res += s1[i];
                    break;
                }
            }
        }
        return res;
    }

    //  dp solution, O(n) = n^2, T(n) = n^2
    class Solution {
    public:
        int longestCommonSubsequence(string text1, string text2) {
            if (text1.length() == 0 || text2.length() == 0) return 0;
            
            int row = text1.length();
            int col = text1.length();
            
            vector<vector<int> > dp(row + 1, vector<int>(col + 1, 0));
            
            for (int i = 1; i <= row; ++i)
            {
                for (int j = 1; j <= col; ++j)
                {
                    if (text1[i-1] == text2[j-1])
                    {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    }
                    else
                    {
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
            
            return dp[row][col];
        }
};

};
