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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(NULL==s && NULL==t)
        {
            return true;
        }

        if(NULL==s || NULL==t)
        {
            return false;
        }

        if(s->val==t->val)
        {
            return isEqual(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t);
        }

        return isSubtree(s->left,t) || isSubtree(s->right,t);
    }

    bool isEqual(TreeNode* s, TreeNode* t)
    {
        if(NULL==s && NULL==t)
        {
            return true;
        }

        if(NULL==s || NULL==t)
        {
            return false;
        }

        if(s->val==t->val)
        {
            return isEqual(s->left,t->left) && isEqual(s->right,t->right);
        }

        return false;
    }
};