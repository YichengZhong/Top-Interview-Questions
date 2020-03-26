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
   int pathSum(TreeNode* root, int sum) {
        if (root==NULL) return 0;
        return DFS(root,sum);
        
    }

    int solve(TreeNode* curr, int target)
    {
        int ans=0;
        if(curr==NULL) return 0;
        if(curr->val == target) ans++;
        ans+=solve(curr->left, target-curr->val);
        ans+=solve(curr->right,target-curr->val);
        return ans;
    }

    int DFS(TreeNode* curr, int target)
    {
        int ans=0;
        if(curr==NULL) return 0;
        ans+= solve(curr,target);
        ans+=DFS(curr->left,target);
        ans+=DFS(curr->right,target);
        return ans;
    }
};