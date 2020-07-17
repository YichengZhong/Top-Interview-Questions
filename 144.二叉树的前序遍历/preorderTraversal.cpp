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
    vector<int> preorderTraversal(TreeNode* root)
    {
        if(root!=NULL)
        {
            ret.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return ret;
    }
};