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
    vector<int> v_out;
    bool isValidBST(TreeNode* root) {
        inorderTraversal(root);
        
        if(v_out.size()==0)
            return true;
        
        for(int i=0;i<v_out.size()-1;++i)
        {
            if(v_out[i]>=v_out[i+1])
                return false;
        }
        
        return true;
        
    }
    void inorderTraversal(TreeNode* root) {
        v_out.clear();
        
        help(root);
    }
    
    void help(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        help(root->left);
        v_out.push_back(root->val);
        help(root->right);
    }
};