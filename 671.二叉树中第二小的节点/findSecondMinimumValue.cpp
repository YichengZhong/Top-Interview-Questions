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
    vector<int>nodevalue;
    int findSecondMinimumValue(TreeNode* root) {
        nodevalue.clear();
        helpDFS(root);

        sort(nodevalue.begin(),nodevalue.end());

        nodevalue.erase(unique(nodevalue.begin(),nodevalue.end()),nodevalue.end());

        if(nodevalue.size()<=1) return -1;

        return nodevalue[1];
    }

    void helpDFS(TreeNode* root)
    {
        if(NULL==root) return ;

        helpDFS(root->left);
        nodevalue.push_back(root->val);
        helpDFS(root->right);
    }
};