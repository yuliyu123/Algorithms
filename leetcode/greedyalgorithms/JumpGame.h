//
// Created by loohan on 2019/2/25.
//

#ifndef ALGORITHMMS_JUMPGAME_H
#define ALGORITHMMS_JUMPGAME_H

/*
 * 贪心算法
 * https://leetcode-cn.com/problems/jump-game/solution/
 * */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 1; // 最右能到的地步
        for (int i = 0; i < reach && reach < nums.size(); ++i) {
            reach = std::max(reach, i + 1 + nums[i]);  // 找下一个
        }
        return reach >= nums.size(); // 能够走完
    }
};

#endif //ALGORITHMMS_JUMPGAME_H
