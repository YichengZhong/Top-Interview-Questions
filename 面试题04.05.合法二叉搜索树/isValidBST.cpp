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
private:
    bool flag;
    long val;
    void Dfs(TreeNode* root)
    {
        if(root==NULL||!flag)
        {
            return;
        }
        Dfs(root->left);
        if(root->val>val)
        {
            val=root->val;
        }
        else
        {
            flag=false;
            return;
        }
        Dfs(root->right);
    }
public:
    bool isValidBST(TreeNode* root) 
    {
        flag=true;
        val=LONG_MIN;
        Dfs(root);
        return flag;
    }
};