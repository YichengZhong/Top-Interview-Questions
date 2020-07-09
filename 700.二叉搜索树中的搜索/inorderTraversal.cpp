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
     TreeNode *ret;
    int g_val;
    TreeNode * inorderTraversal(TreeNode* root)
    {
        if(root!=NULL)
        {
            inorderTraversal(root->left);
            if(root->val==g_val)
            {
                 ret=root;
            }
           
            inorderTraversal(root->right);
        }
        return ret;
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        g_val=val;
        ret=NULL;
        
        return inorderTraversal(root);
    }
};