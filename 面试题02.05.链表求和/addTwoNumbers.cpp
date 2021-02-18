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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 ==NULL) return NULL;
        if(l1 == NULL || l2 == NULL) return l1==NULL?l2:l1;

        ListNode *Head=new ListNode;
        ListNode *temp=Head;
        int flag=0;
        while(l1 !=NULL || l2 !=NULL)
        {
            ListNode *next=new ListNode;
            int l1_value=(l1==NULL?0:l1->val);
            int l2_value=(l2==NULL?0:l2->val);
            next->val=(l1_value+l2_value+flag)%10;
            flag=(l1_value+l2_value+flag)/10;
            temp->next=next;
            temp=next;
            if(l1!=NULL) l1=l1->next;
            if(l2!=NULL) l2=l2->next;
        }

        if(flag!=0) temp->next=new ListNode(1);

        return Head->next;

    }
};