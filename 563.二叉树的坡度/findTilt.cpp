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
    int ans = 0;

    int findTilt(TreeNode* root) {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int sumLeft = dfs(node->left);
        int sumRight = dfs(node->right);
        ans += abs(sumLeft - sumRight);
        return sumLeft + sumRight + node->val;
    } 
};