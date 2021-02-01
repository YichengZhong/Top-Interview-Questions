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
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL && t2==NULL) return true;

        if(t1==NULL || t2==NULL) return false;

        if(t1->val==t2->val) return isTreeEqual(t1, t2);

        return checkSubTree(t1->left,t2) || checkSubTree(t1->right, t2);
    }

    bool isTreeEqual(TreeNode* t1, TreeNode* t2)
    {
        if(t1==NULL && t2==NULL) return true;
        if(t1==NULL || t2==NULL) return false;

        if(t1->val!=t2->val) return false;

        return isTreeEqual(t1->left, t2->left) && isTreeEqual(t1->right, t2->right);
    }
};