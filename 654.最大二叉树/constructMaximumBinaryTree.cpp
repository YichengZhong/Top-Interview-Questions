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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helpDFS(nums,0,nums.size());
    }

    TreeNode *helpDFS(vector<int>& nums,int left,int right)
    {
        if(left>=right) return NULL;

        //找到最大
        int maxIndex=GetMaxIndex(nums,left,right);
        TreeNode *root=new TreeNode(nums[maxIndex]);
        root->left=helpDFS(nums,left,maxIndex);
        root->right=helpDFS(nums,maxIndex+1,right);
        return root;        
    }

    int GetMaxIndex(vector<int>& nums,int left,int right)
    {
        int maxTemp=nums[left];
        int maxIndex=left;

        for(int i=left;i<right&& i<nums.size();++i)
        {
            if(nums[i]>maxTemp)
            {
                maxTemp=nums[i];
                maxIndex=i;
            }
        }
        
        return maxIndex;
    }
};