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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //假设A比B长
    
        if(headA==NULL||headB==NULL)
            return NULL;
    
        struct ListNode* pA=headA;
        struct ListNode* pB=headB;
   
        while(pA!=pB)//遍历两个链表
        {
            pA=pA==NULL?headB:pA->next;//构造链表D
            pB=pB==NULL?headA:pB->next;//构造链表C   
        }
        return pA;
    }
};