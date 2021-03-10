/*
* dfs遍历
*/
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return helper(pRoot) != -1;
    }
    
    int helper(TreeNode* pRoot)
    {
        if (!pRoot) return 0;
        int l = helper(pRoot->left);
        if (l == -1) return -1;
        int r = helper(pRoot->right);
        if (r == -1) return -1;
        if (abs(l - r) > 1) return -1;
        return 1 + max(l, r);
    }
};
