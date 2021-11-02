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
    vector<pair<int,TreeNode*>>mid_node;
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        helpDFS(root);

        sort(mid_node.begin(),mid_node.end());
        for(int i=0;i<mid_node.size();++i)
        {
            if(mid_node[i].first>p->val)
            {
                return mid_node[i].second;
            }
        }

        return NULL;        
    }

    void helpDFS(TreeNode* root)
    {
        if(root==NULL)
            return ;
        
        helpDFS(root->left);
        pair<int,TreeNode*> p2(root->val,root);
        mid_node.push_back(p2);
        helpDFS(root->right);
    }
};