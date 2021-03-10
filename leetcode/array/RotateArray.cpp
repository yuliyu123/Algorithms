// 189. Rotate Array
// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
// https://leetcode.com/problems/rotate-array/
// 三次反转：整体反转-> 前k个反转 -> 后面的在反转

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverseArr(nums, 0, nums.size());
        reverseArr(nums, 0, k);
        reverseArr(nums, k, nums.size());
    }

    // more effective
    void reverseArr(vector<int>& nums, int l, int h)
    {   
        int mid = (l + h) >> 1;
        for (int i = l; i < mid; ++i)
        {
            std::swap(nums[i], nums[--h]);   
        }
    }
    
    // is equal to above
    // void reverseArr(vector<int>& nums, int l, int h)
    // {   
    //     int mid = (l + h) >> 1;
    //     while (l < mid)
    //     {
    //         std::swap(nums[l++], nums[--h]);
    //     }
    // }
    
    // void reverseArr(vector<int>& nums, int l, int h)
    // {
    //     for (int i = l, j = h - 1; i < h && j > l; ++i, --j)
    //     {
    //         if (i >= j) break;
    //         std::swap(nums[i], nums[j]);   
    //     }
    // }
};

