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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur=head;
        ListNode *pre=head;

        for(int i=0;i<n;i++)
        {
            cur=cur->next;
        }

        if(!cur)
        {
            head=head->next;
            return head;
        }

        while(cur->next)
        {

            pre=pre->next;
            cur=cur->next;
        }

        pre->next=pre->next->next;

        return head;
    }
};