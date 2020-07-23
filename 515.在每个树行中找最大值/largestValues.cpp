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
    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>> v_temp;
        v_temp=levelOrder(root);
        
        vector<int>v_out;
        
        for(int i=0;i<v_temp.size();++i)
        {
           
            int temp=v_temp[i][0];
            for (int j=0;j<v_temp[i].size();++j)
            {
                if(temp<v_temp[i][j])
                {
                    temp=v_temp[i][j];
                }
            }
            
            v_out.push_back(temp);
        }
        
        return v_out;
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
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
        return vec;
    }
};