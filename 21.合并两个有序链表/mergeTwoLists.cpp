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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        struct ListNode *rethead;

    struct ListNode  *nextlist;

    int i=0;

    if(l1 == NULL ) return l2;

    if(l2 == NULL ) return l1;

    if(l1->val < l2->val){

       nextlist = l1;

       l1=l1->next; //必须要有，不然对于每个链表只有一个数的测试用例 [2] [1]死循环

    }else{

       nextlist = l2;

       l2=l2->next;

    }

    rethead= nextlist;

    while(l1 !=NULL  &&l2!=NULL) //等价于 while( l1 &&l2)

    {

        if(l1->val < l2->val){

          nextlist->next = l1;

          l1 = l1->next;

        }else{

          nextlist->next = l2;

          l2 = l2->next;

        }

        nextlist = nextlist ->next;

      

    }

    if(l1)  nextlist->next = l1;

    else  nextlist->next = l2;

    return rethead;

 

 

    }
};