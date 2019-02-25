//
// Created by looperX on 2019-02-08.
// https://leetcode-cn.com/problems/longest-consecutive-sequence/solution/
//

#ifndef ALGORITHMS_LONGESTCONSECUTIVE_H
#define ALGORITHMS_LONGESTCONSECUTIVE_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> used;

        for (auto i : nums)
        {
            used[i] = false;
        }

        int lengthest = 0;
        for (auto i : nums)
        {
            if (used[i]) continue;

            int length = 1;

            for (int j = i+1; used.find(j) != used.end(); ++j)
            {
                used[j] = true;
                ++length;
            }

            for (int j = i - 1; used.find(j) != used.end(); --j)
            {
                used[j] = true;
                ++length;
            }

            lengthest = max(length, lengthest);
        }
        return lengthest;
    }
};

#endif //ALGORITHMS_LONGESTCONSECUTIVE_H
