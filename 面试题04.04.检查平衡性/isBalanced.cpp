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
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }

        int TreeLeftDepth=TreeDepth(root->left);
        int TreeRightDepth=TreeDepth(root->right);

        if(abs(TreeLeftDepth-TreeRightDepth)>1)
        {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right) ;

    }

    int TreeDepth(TreeNode *root)
    {
        if(NULL==root)
        {
            return 0;
        }

        return max(TreeDepth(root->left),TreeDepth(root->right))+1;
    }
};