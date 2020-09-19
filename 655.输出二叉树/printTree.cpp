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
    vector<vector<string>> printTree(TreeNode* root) {
        int TreeDepth=getTreeDepth(root);
        int j=pow(2,TreeDepth)-1;    
        vector<vector<string>> res(TreeDepth,vector<string>(j,""));    //初始化比for循环赋值要快

        //每一个递归节点都是在中间的
        dfs(res,root,0,0,j);
        return res;
    }

    //获取最深
    int getTreeDepth(TreeNode *root)
    {
        if(root==NULL)
        {
            return 0;
        }

        int rightDepth=getTreeDepth(root->right);
        int leftDepth=getTreeDepth(root->left);

        return rightDepth>leftDepth?(rightDepth+1):(leftDepth+1);
    }

    void dfs(vector<vector<string>> &res,TreeNode* t,int depth,int left,int right)
    {
        if(!t)return;
        int mid=(left+right)>>1;
        res[depth][mid]=to_string(t->val);     
        dfs(res,t->left,depth+1,left,mid);
        dfs(res,t->right,depth+1,mid,right);
    }
};