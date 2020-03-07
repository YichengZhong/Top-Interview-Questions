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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        return fun(inorder,postorder,0, inorder.size(), 0,postorder.size()-1);
    }
    
    TreeNode* fun(vector<int>& inorder, vector<int>& postorder,int in_start, int in_end, int post_start, int post_end)
    {
        if(post_start==post_end) 
            return new TreeNode(postorder[post_end]);
        
        if(post_start > post_end) 
            return NULL;
        
        int root_value=postorder[post_end];
        
        TreeNode* root=new TreeNode(root_value);
        
        int i;
        for(i=0;i<in_end;++i)
        {
            if(inorder[i]==root_value)
                break;
        }
        
        root->left=fun(inorder,postorder,in_start, i-1, post_start, post_start+ i-in_start-1);
        root->right=fun(inorder,postorder,i+1, in_end, post_start+i-in_start, post_end-1);
        
        return root;
    }
};