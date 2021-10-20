/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    vector<Node*>out;
    Node* flatten(Node* head) {
        if(NULL==head) return NULL;

        DFSFindNode(head);

        for(int i=1;i<out.size();++i)
        {
            out[i]->prev=out[i-1];
            out[i-1]->next=out[i];
            out[i]->child=NULL;
            out[i-1]->child=NULL;
        }

        return head;
    }

    void DFSFindNode(Node* head)
    {
        if(NULL==head)
            return ;

        out.push_back(head);
        if(head->child!=NULL)
        {
            DFSFindNode(head->child);
        }

        DFSFindNode(head->next);
    }
};