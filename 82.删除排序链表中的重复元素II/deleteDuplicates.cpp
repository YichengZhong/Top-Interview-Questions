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
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(-1),tail = dummy;
        while(head){
            if(head->next == nullptr or head->val != head->next->val){
                tail->next = head;
                tail = head;
            }
            while(head->next and head->val == head->next->val) head = head->next;
            head = head->next;
        }
        tail->next = nullptr;
        return dummy->next;
    }
};