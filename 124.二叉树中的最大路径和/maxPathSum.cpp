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
    int max_sum = INT_MIN;

    int max_gain(TreeNode * node) 
    {
        if (node == NULL) 
        {
            return 0;
        }

        int left_gain = max(max_gain(node->left), 0);
        int right_gain = max(max_gain(node->right), 0);

        int price_newpath = node->val + left_gain + right_gain;

        max_sum = max(max_sum, price_newpath);

        return node->val + max(left_gain, right_gain);
  }

    int maxPathSum(TreeNode * node)
    {
        max_gain(node);
        return max_sum;
    }
};