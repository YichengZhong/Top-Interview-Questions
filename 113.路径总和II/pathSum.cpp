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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        vector<int> temp;
        findPath(root, sum, 0, temp, res);
        return res;
    }
    void findPath(TreeNode* root, int sum, int pathSum, vector<int> temp, vector<vector<int>> &res){
        if(root->left == NULL && root->right == NULL && root->val + pathSum == sum){
            temp.push_back(root->val);
            res.push_back(temp);
            return;
        }
        temp.push_back(root->val);
        if(root->left) findPath(root->left, sum, pathSum + root->val, temp, res);
        if(root->right) findPath(root->right, sum, pathSum + root->val, temp, res);
    }
};