/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> ret;
    vector<int> preorder(Node* root) {
         if(root!=NULL)
        {
            ret.push_back(root->val);
             for(int i=0;i<(root->children).size();++i)
             {
                 preorder((root->children)[i]);
             }
            
        }
        return ret;
        
        
    }
};