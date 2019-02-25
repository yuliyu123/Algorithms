//
// Created by loohan on 2019/2/25.
//

#ifndef ALGORITHMMS_VALIDPARENTNESS_H
#define ALGORITHMMS_VALIDPARENTNESS_H

/*
 * 最长有效括号序列
 * https://leetcode-cn.com/problems/valid-parentheses/
 * */

#include <iostream>
#include <string>
#include <stack>

using namespace std;
// time: O(n), space: O(n)
class Solution
{
public:
    bool isValid(const string& s)
    {
        string left = "([{";
        string right = ")]}";
        stack<char> stk;

        for (auto &c : s)
        {
            if (left.find(c) != string::npos)
            {
                stk.push(c);
            }
            else
            {
                // 若stack为空，或者按照right数组下标找不到left对应的文本，则认为输入无效
                if (stk.empty() || stk.top() != left[right.find(c)])
                {
                    return false;
                }
                else
                {
                    stk.pop(); // 找得到该char，弹出，找下一个
                }
            }
        }
        // 查找完毕能走到这里，stack应该为空。若为空则return true.
        return stk.empty();
    }
};

#endif //ALGORITHMMS_VALIDPARENTNESS_H
