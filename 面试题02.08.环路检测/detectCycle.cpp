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
        map<ListNode *,int>m_find;
        ListNode *temp=head;

        if(NULL==head)
        {
            return NULL;
        }

        while(m_find.find(temp)==m_find.end())
        {
            if(temp->next==NULL)
            {
                return NULL;
            }
            
            m_find[temp]=temp->val;
            temp=temp->next;
        }

        return temp;
    }
};