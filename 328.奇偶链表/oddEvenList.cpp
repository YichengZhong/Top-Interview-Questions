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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
        {
            return NULL;
        }
        
        ListNode *oddHead=head;
        ListNode *evenHead=head->next;
        ListNode *evenHead_temp=evenHead;

        while(evenHead != NULL && evenHead->next != NULL)
        {
            oddHead->next = evenHead->next;
            oddHead = oddHead->next;
            evenHead->next = oddHead->next;
            evenHead = evenHead->next;
        }

        oddHead->next = evenHead_temp;

        return head;
        
    }
};