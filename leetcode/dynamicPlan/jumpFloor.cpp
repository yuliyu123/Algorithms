/*
state function:
f(1) = 1
f(2) = 2
n >= 3:
f(n) = f(n-1) + f(n-2)
*/
class Solution {
public:
    int jumpFloor(int number) {
        int dp[number];
        if (number == 1)
        {
            return 1;
        }
        
        if (number == 2)
        {
            return 2;
        }
        
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= number; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[number];
    }
};
