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
    bool isSymmetric(TreeNode* root) {
       if (root == NULL) 
           return true;
        return fun(root->left, root->right);
    }
    
    bool fun(struct TreeNode* l_root, struct TreeNode* r_root)
    {
        if (l_root == NULL && r_root == NULL) 
            return true;
    
        if (l_root == NULL || r_root == NULL) 
            return false;

  
        return    (l_root->val == r_root->val)&&fun(l_root->left,  r_root->right)&&fun(l_root->right, r_root->left);
}

};