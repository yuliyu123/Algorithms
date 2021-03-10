// https://leetcode.com/problems/palindrome-number/submissions/

class Solution {
public:
    bool isPalindrome(int x) {
        string s = std::to_string(x);
        int l = 0;
        int r = s.length();
        
        while (l < (l + r) >> 1)
        {
            if (s[l++] != s[--r]) return false;
        }
        
        return true;
    }
};
