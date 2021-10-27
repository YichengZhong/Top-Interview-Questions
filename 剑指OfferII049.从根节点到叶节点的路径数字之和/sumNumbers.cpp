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
    int sumNumbers(TreeNode* root) {
        if(NULL==root)
            return 0;
         
        vector<int> res;
        pathSum(root,res);
        
        int sum=0;
        
        for(int i=0;i<res.size();++i)
        {
            sum=sum+res[i];
        }
        
        return sum;
    }
    
    void pathSum(TreeNode* root, vector<int>&res) {
        if(root == NULL) return;
        findPath(root, 0, res);
    }
    
    void findPath(TreeNode* root, int pathSum, vector<int> &res){
        pathSum=10*pathSum+root->val;
        if(root->left == NULL && root->right == NULL)
        {
            res.push_back(pathSum);
            return;
        }
        if(root->left) findPath(root->left,  pathSum ,  res);
        if(root->right) findPath(root->right, pathSum, res);
    }
};