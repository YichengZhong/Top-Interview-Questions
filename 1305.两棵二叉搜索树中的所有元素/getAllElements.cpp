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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v_out;
        v_out.clear();
        
        if(NULL==root1 && NULL==root2)
        {
            return v_out;
        }
        
        getEle(root1,v_out);
        getEle(root2,v_out);
        
        sort(v_out.begin(),v_out.end());
        
        return v_out;
        
    }
    
    void getEle(TreeNode* root,vector<int> &v_out)
    {
        if(root!=NULL)
        {
            getEle(root->left,v_out);
            v_out.push_back(root->val);
            getEle(root->right,v_out);
        }
    }
};