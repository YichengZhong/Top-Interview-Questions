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
        if(head==NULL)
        {
            return NULL;
        }

        vector<int>v_val;
        v_val.clear();

        ListNode* temp=head;

        while(temp!=NULL)
        {
            v_val.push_back(temp->val);
            temp=temp->next;
        }

        sort(v_val.begin(),v_val.end());

        ListNode* out=head;
        for(int i=0;i<v_val.size();++i)
        {
            if(0==i)
            {
                out=new ListNode(v_val[i]);
                out->next=NULL;
                head=out;
            }
            else
            {
                 ListNode* temp=new ListNode(v_val[i]);
                 out->next=temp;
                 out=temp;
            }
        }

        out->next=NULL;

        return head;

    }
};