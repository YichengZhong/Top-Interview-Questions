/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(NULL==head)
        {
            return NULL;
        }

        if(0==k)
        {
            return head;
        }
        
        ListNode *out_head=head;
        ListNode *temp_head=head;
        
        int ListCount=0;
        int true_k=0;//真正移动数目
        while(temp_head!=NULL)
        {
            ListCount++;
            temp_head=temp_head->next;
        }
        
        true_k=k%ListCount;
        
        temp_head=head;
        while(temp_head->next!=NULL)
        {
            temp_head=temp_head->next;
        }
        
        temp_head->next=head;
        
        while(true_k>0)
        {
            head=head->next;
            true_k--;
        }

        out_head=head->next;
        head->next=NULL;

        return out_head;     
    }
};