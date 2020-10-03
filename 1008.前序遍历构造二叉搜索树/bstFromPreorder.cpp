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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>midorder=preorder;
        sort(midorder.begin(),midorder.end());

        return buildTreeHelper(preorder, 0, preorder.size(), midorder, 0, midorder.size());  
    }

    TreeNode* buildTreeHelper(vector<int>& preorder, int p_start, int p_end, vector<int>& inorder, int i_start, int i_end)
    {
        if(p_end==p_start)
        {
            return NULL;
        }
        
        int root_val=preorder[p_start];
        TreeNode* root=new TreeNode(root_val);
        
        int i_root_index = 0;
        for (int i = i_start; i < i_end; i++)
        {
            if (root_val == inorder[i]) 
            {
                i_root_index = i;
                break;
            }
        }
        
        int leftNum = i_root_index - i_start;
        //递归的构造左子树
        root->left = buildTreeHelper(preorder, p_start + 1, p_start + leftNum + 1, inorder, i_start, i_root_index);
        //递归的构造右子树
        root->right = buildTreeHelper(preorder, p_start + leftNum + 1, p_end, inorder, i_root_index + 1, i_end);
        return root;
    }
};