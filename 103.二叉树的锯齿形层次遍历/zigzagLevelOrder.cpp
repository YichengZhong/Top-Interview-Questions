/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <algorithm>
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //右往左时右先入栈，左往右时，左先入栈。然后要两个栈分别保存每一层级的。
        //这里借鉴了树的层次遍历的思想，不过那是用队列
        vector<vector<int>> r;
        if (!root) return r;
        stack<TreeNode *> d1, d2;
        d1.push(root);
        TreeNode *curr = nullptr;
        vector<int> tmp;
        while (true) {
            while (!d1.empty()) {
                curr = d1.top();
                d1.pop();
                tmp.push_back(curr->val);
                if (curr->left) d2.push(curr->left);
                if (curr->right) d2.push(curr->right);
            }
            if (!tmp.empty()) {
                r.push_back(tmp);
                tmp.clear();
            } else break;

            while (!d2.empty()) {
                curr = d2.top();
                d2.pop();
                tmp.push_back(curr->val);
                if (curr->right) d1.push(curr->right);
                if (curr->left) d1.push(curr->left);
            }
            if (!tmp.empty()) {
                r.push_back(tmp);
                tmp.clear();
            } else break;
        }
        return r;
    }
};