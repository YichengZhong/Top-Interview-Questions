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
    bool hasPathSum(TreeNode* root, int sum) {

        if(root == NULL) return false;

        return check(root, 0, sum);

    }

    

    bool check(TreeNode* t, int sum, int a) {

        if(t == NULL&&sum == a) return true;

        if(t == NULL) return false;

        if(t->left == NULL&&t->right != NULL) return check(t->right, sum+t->val, a);

        if(t->left != NULL&&t->right == NULL) return check(t->left, sum+t->val, a);

        return check(t->left, sum+t->val, a)||check(t->right, sum+t->val, a);

    }
};