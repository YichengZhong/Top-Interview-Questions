/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* node = new Node(insertVal);
        
        if (head == nullptr)            //处理链表为空的情况
        {
            head = node;
            head->next = head;
        }
        else if (head->next == head)    //处理链表中只有一个节点的情况
        {
            head->next = node;
            node->next = head;
        }
        else                            //链表中超过一个节点的情况
        {
            insertCore(head, node);
        }

        return head;
    }

    void insertCore(Node* head, Node* node)
    {
        Node *cur = head, *next = head->next, *maxVal = head;

        //试图找到相邻的两个节点cur和next，使待插入值大于cur且小于next
        while (!(cur->val <= node->val && next->val >= node->val) && next != head)
        {
            cur = next;
            next = next->next;
            if (cur->val >= maxVal->val) maxVal = cur;          //实时更新最大值
        }

        if (cur->val <= node->val && next->val >= node->val)
        {
            cur->next = node;
            node->next = next;
        }
        else    //如果没有找到符合条件的节点，说明新节点比所有的节点值都大或者都小
        {       //那么就把新节点插入到值最大的节点后面
            node->next = maxVal->next;      //注意：maxVal->next就是最小值节点
            maxVal->next = node;
        }
    }
};