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
    ListNode* middleNode(ListNode* head) {
        if(NULL==head)
        {
            return NULL;
        }

        if(NULL==head->next)
        {
            return head;
        }

        ListNode* fast=head;
        ListNode* slow=head;

        int cout=1;
        while(slow->next!=NULL)
        {
            cout++;
            slow=slow->next;
        }

        slow=head;
        while(fast->next!=NULL&&fast->next->next!=NULL&&slow->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }

        if(cout%2==0)
        {
            return slow->next;
        }
        return slow;


    }
};