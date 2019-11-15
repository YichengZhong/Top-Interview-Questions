/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(NULL==root)
        {
            return NULL;
        }

        if(root->left!=NULL)
        {
            if(root->right!=NULL)
            {
                root->left->next=root->right;
            }
            else
            {
                root->left->next=findNextNode(root);
            }
        }

        if(root->right != NULL)
        {
            root->right->next = findNextNode(root);
        }
        
        //递归
        connect(root->right);
        connect(root->left);

        return root;
    }

    Node *findNextNode(Node * root)
    {
        if(root->next==NULL)
        {
            return NULL;
        }

        while(root->next!=NULL)
        {
            if(root->next->left!=NULL)
            {
                return root->next->left;
            }
            if(root->next->right != NULL) 
            {
                return root->next->right;
            }
            root = root->next;
        }

        return NULL;
    }
};