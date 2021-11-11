/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) 
        {
            TreeNode *node = que.front();
            que.pop();
            v.emplace_back(node);
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
    }
    
    int insert(int val) {
        TreeNode *node = new TreeNode(val);
        v.emplace_back(node);
        TreeNode *father = v[v.size() / 2 - 1];
        if ((v.size() & 1) == 0) father->left = node;
        else father->right = node;
        return father->val;
    }
    
    TreeNode* get_root() 
    {
        return root;
    }
    TreeNode *root = nullptr;
    vector<TreeNode*> v;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */