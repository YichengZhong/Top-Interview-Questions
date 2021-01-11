/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(nullptr==head) return head;

        ListNode *out=head;
        //一次遍历获取第k个指针
        ListNode* k_Nodes=nullptr;
        k_Nodes=getKthFromStart(head,k);

        //一次遍历获取倒数第k个指针
        ListNode* k_NodesFromEnd=nullptr;
        k_NodesFromEnd=getKthFromEnd(head,k);

        int value=0;
        value=k_Nodes->val;
        k_Nodes->val=k_NodesFromEnd->val;
        k_NodesFromEnd->val=value;

        return head;
    }

    ListNode* getKthFromEnd(ListNode* head, int k) 
    {
        ListNode* former = head;
        while(k>0)
        {
            former = former->next;
            k--;
        }
        while(former)
        {
            head = head->next;
            former = former->next;
        }
        return head;
    }

     ListNode* getKthFromStart(ListNode* head, int k) 
     {
        if(k==1) return head;
        ListNode* temp=head;

        for(int i=0;i<k-1;++i)
        {
            temp=temp->next;
        }

        return temp;
    }
    
};