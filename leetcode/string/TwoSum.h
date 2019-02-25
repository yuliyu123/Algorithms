//
//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
//
//你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
//
//示例:
//
//给定 nums = [2, 7, 11, 15], target = 9
//
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回 [0, 1]
// Created by looperX on 2019-02-08.
//

#ifndef ALGORITHMS_TWOSUM_H
#define ALGORITHMS_TWOSUM_H

#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

//  二次哈希算法, O(n) = n, T(n) = n
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target)
//    {
//        unordered_map<int, int> map;
//        vector<int> result;
//
//        for (int i = 0; i < nums.size(); i++)
//        {
//            map[nums[i]] = i;
//        }
//
//        for (int i = 0; i < nums.size(); i++)
//        {
//            const int gap = target - nums[i];
//            if (map.find(gap) != map.end() && map[gap] > i)
//            {
//                result.push_back(i);
//                result.push_back(map[gap]);
//                break;
//            }
//        }
//        return result;
//    }
//};


// 一次哈希, 边遍历，边放入map中, 该效率最高， O(n) = n, T(n) = n
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        cout << "twoSum solution" << endl;
        unordered_map<int, int> map;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++)
        {
            const int gap = target - nums[i];
            if (map.find(gap) != map.end() && map[gap] != i)
            {
                result.push_back(i < map[gap] ? i : map[gap]);
                result.push_back(i > map[gap] ? i : map[gap]);
                break;
            }
            map[nums[i]] = i;
        }
        return result;
    }
};

#endif //ALGORITHMS_TWOSUM_H
