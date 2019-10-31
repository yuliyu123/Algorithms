//
// Created by loohan on 2019/10/31.
//
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
            cout << "less 0" << endl;
            return false;
        }
        string s = std::to_string(x);
        cout << s << endl;

        int j = s.size() - 1;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == s[j])
            {
                if (j <= i) break;
            }
            else
            {
                cout << "not" << endl;
                return false;
            }
            j--;
        }
        cout << "yes" << endl;
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isPalindrome(121) << endl;
    cout << s.isPalindrome(-121) << endl;
    cout << s.isPalindrome(10) << endl;
    cout << s.isPalindrome(15532) << endl;
    cout << s.isPalindrome(5445) << endl;
}
