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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        res.clear();
        
        stack<TreeNode*>stack_temp;
        
        TreeNode *curr = root;
        
        while (curr != NULL || !stack_temp.empty()) 
        {
            while (curr != NULL) 
            {
                stack_temp.push(curr);
                curr = curr->left;
            }
            curr = stack_temp.top();
            stack_temp.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
        return res;
    }
    
   
};