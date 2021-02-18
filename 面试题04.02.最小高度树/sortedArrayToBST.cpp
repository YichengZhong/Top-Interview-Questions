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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helpDFS(nums,0,nums.size()-1);
    }

    TreeNode* helpDFS(vector<int>& nums,int left,int right)
    {
        if(left<0 || right >=nums.size()) return NULL;
        if(left>right) return NULL;

        TreeNode *root=new TreeNode(nums[(left+right)/2]);

        root->left=helpDFS(nums,left,(left+right)/2-1);
        root->right=helpDFS(nums,(left+right)/2+1,right);

        return root;
    }
};