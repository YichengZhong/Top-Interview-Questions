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
    vector<int> v_val;
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        v_val.clear();

        getTreeNodeVale(root);

        v_val.push_back(val);
        sort(v_val.begin(),v_val.end());

        TreeNode* temp=sortedArrayToBST(v_val);

        return temp;        
    }

    void getTreeNodeVale(TreeNode *root)
    {
        if(root==NULL)
        {
            return ;
        }

        getTreeNodeVale(root->left);
        v_val.push_back(root->val);
        getTreeNodeVale(root->right);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        if(nums.size()==0)
        {
            return NULL;
        }
        
        return genTree(nums,0,nums.size()-1);
    }
    
    TreeNode *genTree(vector<int>& nums,int left,int right)
    {
        if(left>right)
            return NULL;
        
        int mid=(left+right)/2;
        TreeNode *root=new TreeNode(nums[mid]);
        //root->val=nums[mid];
        root->left=genTree(nums,left,mid-1);
        root->right=genTree(nums,mid+1,right);
        
        return root;
        
    }
};