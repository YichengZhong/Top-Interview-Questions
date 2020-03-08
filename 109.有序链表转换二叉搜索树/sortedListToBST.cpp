/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *genTree(vector<int>& nums,int left,int right)
    {
        if(left>right)
            return NULL;
        
        int mid=(left+right)/2;
        TreeNode *root=new TreeNode(nums[mid]);
        root->val=nums[mid];
        root->left=genTree(nums,left,mid-1);
        root->right=genTree(nums,mid+1,right);
        
        return root;
        
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>v_nums;
        v_nums.clear();
        
        while(head!=NULL)
        {
            v_nums.push_back(head->val);
            head=head->next;
        }
        
        if(v_nums.size()==0)
            return NULL;
        
        return genTree(v_nums,0,v_nums.size()-1);        
    }
    
    
};