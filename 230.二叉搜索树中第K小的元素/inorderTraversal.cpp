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
    vector<int> ret;
    vector<int> inorderTraversal(TreeNode* root)
    {
        if(root!=NULL)
        {
            inorderTraversal(root->left);
            ret.push_back(root->val);
            inorderTraversal(root->right);
        }
        return ret;
    }
    int kthSmallest(TreeNode* root, int k) {
        inorderTraversal(root);
        return(ret[k-1]);
        
        
    }
};