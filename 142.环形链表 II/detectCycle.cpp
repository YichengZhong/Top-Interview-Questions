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
    ListNode *detectCycle(ListNode *head) {
         struct ListNode *p_fast=head;
        struct ListNode *p_slow=head;
        
        while(p_slow!=NULL && p_fast!=NULL && p_fast->next!=NULL)
        {
            p_slow=p_slow->next;
            p_fast=p_fast->next->next;
            
            if(p_slow==p_fast)
            {
                p_fast = head;

                while(p_slow != p_fast)

                {

                    p_slow = p_slow->next;

                    p_fast = p_fast->next;                    

                }
                
                return p_slow;

            }
        }
        
        return NULL;
        
    }
};