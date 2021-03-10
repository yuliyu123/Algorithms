// solution 1
class Solution {
public:
    bool dfs(TreeNode* root, TreeNode* target, int& distance, const int& k, vector<int>& result){
        if(root)
        {
            if(root==target){distance=0;}
            if(distance++==k){result.push_back(root->val);}
            
            bool left = dfs(root->left,target,distance,k,result);
            if(left){
                if(++distance==k){result.push_back(root->val);}
                distance++;
            }
            
            bool right = dfs(root->right,target,distance,k,result);
            if(right)
            {
                if(++distance==k){result.push_back(root->val);}
                distance++;
                dfs(root->left,target,distance,k,result);
            }
            distance--;
            return (right||left||target==root);
        }
        else
        {
        	return false;
        }
    }

     vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        int distance=INT_MAX/2;
        vector<int>result;
        dfs(root,target,distance,K,result);
        return result;
    }
};

// solution 2
class Solution {
public:

vector<int> result;

void nodesBelow(TreeNode* root, int k){
    
    if(root==NULL || k<0)return ;
    if(k==0){
        result.push_back(root->val);
        return;
    }
    nodesBelow(root->left , k-1);
    nodesBelow(root->right  , k-1);
    
}
int KdistanceNodes(TreeNode* root , TreeNode* target , int k){
    
    if(root==NULL) return -1;
    
    if(root==target){
        nodesBelow(root,k);
        return 0;
    }
    
    int dl = KdistanceNodes(root->left , target , k);
    
    if(dl!=-1){
        
        
        if(dl+1==k){
            result.push_back(root->val);
        }
        
        else
        nodesBelow(root->right,k-dl-2);
        return dl+1;
    }

    int dr = KdistanceNodes(root->right , target , k);
    if(dr!=-1){   
        if(dr+1==k){
            result.push_back(root->val);
        }
        
        else
            nodesBelow(root->left,k-dr-2);
        
        return dr+1;
    }
    return -1;
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
{
    KdistanceNodes(root, target, k);
    return result;
}

};


