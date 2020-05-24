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
    bool isUnivalTree(TreeNode* root) {
         bool left_correct = (root->left == NULL ||
                (root->val == root->left->val && isUnivalTree(root->left)));
        bool right_correct = (root->right == NULL ||
                (root->val == root->right->val && isUnivalTree(root->right)));
        return left_correct && right_correct;

    }
};