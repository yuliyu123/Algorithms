//
// Created by looperX on 7/26/21.
//

#ifndef ALGORITHMMS_ISCONTINUOUS_H
#define ALGORITHMMS_ISCONTINUOUS_H


// solution1：set+遍历 时间空间复杂度： O(n)
class Solution {
public:
    bool IsContinuous( vector<int> numbers) {
        if (numbers.empty()) return false;
        set<int> st;
        int max_ = 0, min_ = 14;
        for (int val : numbers) {
            if (val > 0) {
                if (st.count(val) > 0) return false;
                st.insert(val);
                max_ = max(max_, val);
                min_ = min(min_, val);
            }
        }
        return max_ - min_ < 5;
    }
};

// 方法二：排序+遍历， 时间：O(NlogN) 空间：O(1)
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.empty()) return false;
        sort(numbers.begin(), numbers.end());
        int i = 0, sz = numbers.size();
        for (int j=0; j<sz; ++j) {
            if (numbers[j] == 0) {
                ++i; // i 记录最小值的下标
                continue;
            }
            if (j+1<sz && numbers[j] == numbers[j+1]) return false;
        }
        return numbers.back() - numbers[i] < 5;
    }
};

#endif //ALGORITHMMS_ISCONTINUOUS_H
