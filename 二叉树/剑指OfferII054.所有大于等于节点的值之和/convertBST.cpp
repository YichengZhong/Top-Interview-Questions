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
    vector<int>BST_value;
    TreeNode* convertBST(TreeNode* root) {
        BST_value.clear();
        getNodeValue(root);

        convertVaule(root);
        return root;
    }

    void getNodeValue(TreeNode* root)
    {
        if(nullptr==root)return;

        getNodeValue(root->left);
        BST_value.push_back(root->val);
        getNodeValue(root->right);
    }

    void convertVaule(TreeNode* root)
    {
        if(nullptr==root) return;
        convertVaule(root->left);
        auto location_index=find(BST_value.begin(),BST_value.end(),root->val);
        root->val=accumulate(location_index,BST_value.end(),0);
        convertVaule(root->right);
    }
};