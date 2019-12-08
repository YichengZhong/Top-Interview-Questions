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
    int dfs(TreeNode* root,unordered_map<int, int>& M)
    {
        if(NULL==root)
        {
            return 0;
        }

        int left=dfs(root->left,M);
        int right=dfs(root->right,M);
        int sum=left+right+root->val;

        M[sum]++;

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> M;
        vector<int> res;
        dfs(root,M);

        int maxTime = 0;
        for (auto item : M) 
        {
            maxTime = max(maxTime, item.second);
        }
        
        for (auto item : M)
        {
            if (item.second == maxTime)
            {
                res.push_back(item.first);
            }
        }
        
        return res;
    }
};