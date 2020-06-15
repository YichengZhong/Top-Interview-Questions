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
    int countNodes(TreeNode* root) {
        inorderTraversal(root);
        
        return ret.size();
        
    }
    vector<int> ret;
    void inorderTraversal(TreeNode* root)
    {
        if(root!=NULL)
        {
            inorderTraversal(root->left);
            ret.push_back(root->val);
            inorderTraversal(root->right);
        }
    }
};