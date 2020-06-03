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
    int count;
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int,int>m_temp;
        count=0;

        if(root==NULL)
        {
            return 0;
        }

        findPath(root,m_temp);
        return count;        
    }

    void findPath(TreeNode*root,map<int,int>m_temp)
    {
        if(root==NULL)
        {
            return;
        }

        auto iter1 = m_temp.find(root->val);
        if(iter1 != m_temp.end())
        {
            m_temp[root->val]++;
        }
        else
        {
            m_temp[root->val]=1;
        }

        if(root->left==NULL && root->right==NULL)
        {
            
            if(checkPalindromicMap(m_temp))
            {
                count++;
                return;
            }
        }

        if(root->left)
        {
            findPath(root->left,m_temp);
        } 
            
        if(root->right) 
        {
            findPath(root->right, m_temp);
        }
    }

    bool checkPalindromicMap(map<int,int>m_temp)
    {
        int single=0;

        for(auto iter=m_temp.begin();iter!=m_temp.end();++iter)
        {
            if((iter->second)%2==1)
            {
                single++;
            }
        }

        if(single>1)
        {
            return false;
        }

        return true;
    }
};