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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> vec;

        if(root==NULL)
        {
            return vec;
        }       

        queue<Node*> que;
        que.push(root);

        while(!que.empty())
        {

            int size=que.size();
            vector<int> vec_temp;

            while(size--)
            {

                Node* t = que.front();
                vec_temp.push_back(que.front()->val);
                que.pop();    

                for(int i=0;i<t->children.size();++i)
                {
                    que.push(t->children[i]);
                }
            }
            vec.push_back(vec_temp);
        }
        return vec;
        
    }
};