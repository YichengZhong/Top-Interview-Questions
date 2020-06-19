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
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;

        int rightDepth=maxDepth(root->right);
        int leftDepth=maxDepth(root->left);
        
        return rightDepth>leftDepth?(rightDepth+1):(leftDepth+1);
    }
    
   
};