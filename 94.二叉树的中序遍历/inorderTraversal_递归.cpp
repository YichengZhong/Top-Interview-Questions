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
    vector<int> inorderTraversal(TreeNode* root) {
        v_out.clear();
        
        help(root);
        
        return v_out;
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