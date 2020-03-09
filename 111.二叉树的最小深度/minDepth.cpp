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
    int minDepth(TreeNode* root) {
         int min_depth=help(root);
        return min_depth;  
        
    }
    
    int help(TreeNode* root)
    {
         if (!root) 
           return 0;
        
        if ((root->left == NULL) && (root->right == NULL)) {
          return 1;
        }
        
        int min_Depth=1000000;
        
        if(root->left!=NULL)
        {
            min_Depth = min( help(root->left),min_Depth);
        }
        
        if(root->right!=NULL)
        {
            min_Depth = min(help(root->right),min_Depth);
        }
                
        return 1+min_Depth;
    }
};