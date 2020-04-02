//
// Created by looperX on 2020-08-26.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /**
     *
     * @param root TreeNode类
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > levelOrder(TreeNode* root) {
        // write code here
        vector<vector<int>> res;
        if (root == nullptr) return res;

        std::queue<std::pair<TreeNode*, int>> q;
        TreeNode* top;

        int level = 0;
        q.push({root, level});

        while (!q.empty())
        {
            top = q.front().first;
            level = q.front().second;
            q.pop();


            // endpoint node is null, insert empty vector
            if (level == res.size())
                res.push_back(vector<int>());

            res[level].push_back(top->val);
            if (top->left)
            {
                q.push({top->left, level + 1});
            }
            if (top->right)
            {
                q.push({top->right, level + 1});
            }
        }
        return res;
    }
};
