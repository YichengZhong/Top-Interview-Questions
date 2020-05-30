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
    ListNode* removeElements(ListNode* head, int val) {
       if(head == NULL)
            return NULL;
        
        ListNode FirstNode(0);
        FirstNode.next = head;
        
        ListNode* p = &FirstNode;
        while(p != NULL)
        {
            ListNode* tmp = p->next;
            if(tmp !=  NULL && tmp->val == val )
            {
                p->next = tmp->next;
                delete tmp; 
            }
            else
                p= p->next;
        }
        
        return FirstNode.next;

        
    }
};