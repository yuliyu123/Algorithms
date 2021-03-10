// Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/


class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;
        
        while (l < r)
        {
            if (!isalnum(s[l])) ++l;
            else if (!isalnum(s[r])) --r;
            else
            {
                if (tolower(s[l]) != tolower(s[r]))
                {
                    return false;
                }
                ++l;
                --r;
            }
        }
        return true;
    }
};
