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
    long sumTree;
    long maxValue;
    long maxProduct(TreeNode* root) {
        sumTree=getTreeSum(root);
        maxValue=0;
        getMaxTree(root);

        return maxValue%1000000007;
    }

    long getTreeSum(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }

        return root->val+getTreeSum(root->left)+getTreeSum(root->right);
    }

    long getMaxTree(TreeNode* root)
    {
        if(NULL==root)
        {
            return 0;
        }

        long left = getMaxTree(root->left);
        long right = getMaxTree(root->right);

        long product1 = (long)(sumTree - left) * left; 
        long product2 = (long)(sumTree - right) * right;

        if(maxValue<product1)
        {
            maxValue=product1;
        }

        if(maxValue<product2)
        {
            maxValue=product2;
        }

        return left + right + root->val;
    }
};