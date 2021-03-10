// https://leetcode.com/problems/shuffle-an-array/

class Solution {
public:
    Solution(vector<int>& nums) {
        origNums = nums;
        copyNums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origNums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if (copyNums.size() > 0)
        {
            int i = rand() % copyNums.size();
            int j = rand() % copyNums.size();
            swap(copyNums[i], copyNums[j]);
        }
        
        return copyNums;
    }
    
    private:
        vector<int> origNums;
        vector<int> copyNums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
