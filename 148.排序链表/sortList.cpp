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

bool lessmark(ListNode* stItem1, ListNode* stItem2)
 {
     return stItem1->val < stItem2->val;
 }

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(nullptr==head)
            return nullptr;

        vector<ListNode*>sortNode={};
        ListNode* temp=head;

        while(temp!=nullptr)
        {
            sortNode.push_back(temp);
            temp=temp->next;
        }

        sort(sortNode.begin(),sortNode.end(),lessmark);

        ListNode* newhead=sortNode[0];
        for(int i=1;i<sortNode.size();++i)
        {
            sortNode[i-1]->next=sortNode[i];
        }
        
        sortNode[sortNode.size()-1]->next=nullptr;

        return newhead;       
    }
};