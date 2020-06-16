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
    vector<int>v_ret;
    void getLeftNode(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        if(root->left!=0 && root->left->left==NULL &&  root->left->right==NULL)
        {
            v_ret.push_back(root->left->val);
        }
        
        getLeftNode(root->left);
        getLeftNode(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        getLeftNode(root);
        
        int sum=0;
        
        for(int i=0;i<v_ret.size();++i)
        {
            sum=sum+v_ret[i];
        }
        
        return sum;     
    }
};