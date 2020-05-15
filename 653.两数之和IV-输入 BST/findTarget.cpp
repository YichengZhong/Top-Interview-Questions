/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>v_val;
    bool findTarget(TreeNode* root, int k) {
        v_val.clear();
        getVal(root);
        
        int start=0,end=v_val.size()-1;
        
        while(start!=end)
        {
            if((v_val[start]+v_val[end])==k)
            {
                return true;
            }
            
            if((v_val[start]+v_val[end])>k)
            {
                end=end-1;
                continue;
            }
            
            if((v_val[start]+v_val[end])<k)
            {
                start=start+1;
                continue;
            }
        }
        
        return false;
        
    }
    
    void getVal(TreeNode* root)
    {
        if(NULL==root)
        {
            return ;
        }
        
        getVal(root->left);
        v_val.push_back(root->val);
        getVal(root->right);
    }
};