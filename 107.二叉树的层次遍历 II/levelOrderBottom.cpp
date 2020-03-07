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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> vec;

        if(root==NULL)
        {
            return vec;
        }       

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty())
        {

            int size=que.size();
            vector<int> vec_temp;

            while(size--)
            {

                TreeNode* t = que.front();
                vec_temp.push_back(que.front()->val);
                que.pop();    

                if(t->left)
                {
                    que.push(t->left);
                }

                if(t->right)
                {
                    que.push(t->right);
                }
            }
            vec.push_back(vec_temp);
        }
        
        reverse(vec.begin(),vec.end());
        return vec;
        
    }
};