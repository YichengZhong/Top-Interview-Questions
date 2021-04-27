/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum;
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum=0;
        helpDFS(root,low,high);

        return sum;
    }

    void helpDFS(TreeNode *root, int low, int high)
    {
        if(nullptr==root) return;
        helpDFS(root->left, low, high);
        if(root->val>=low && root->val<=high)
        {
            sum=sum+root->val;
        }
        helpDFS(root->right,low,high);
    }
};