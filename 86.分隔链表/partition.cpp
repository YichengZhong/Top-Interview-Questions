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
    ListNode* partition(ListNode* head, int x) {
        if(NULL==head)
        {
            return NULL;
        }

        ListNode *List_First=new ListNode(-1);;
        ListNode *List_Second=new ListNode(-1);
        ListNode *p1=List_First;
        ListNode *p2=List_Second;

        while(head!=NULL)
        {
            ListNode *p_temp=new ListNode(head->val);
            if(head->val<x)
            {
                p1->next=p_temp;
                p1=p1->next;
            }
            else
            {
                p2->next=p_temp;
                p2=p2->next;
            }
            head=head->next;
        }

        p2->next=NULL;
        p1->next=List_Second->next;
        return List_First->next;        
    }
};