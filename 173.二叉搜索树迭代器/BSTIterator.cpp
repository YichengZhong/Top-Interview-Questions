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
class BSTIterator {
public:
    int startIndex;
    vector<int>TreeNodeValList;
    BSTIterator(TreeNode* root) {
        startIndex=0;
        TreeNodeValList.clear();
        getTreeNodeValue(root);
    }
    
    int next() {
        startIndex++;
        return TreeNodeValList[startIndex-1];

    }
    
    bool hasNext() {
        if(TreeNodeValList.size()>0 && startIndex<TreeNodeValList.size()) return true;
        return false;

    }

    void getTreeNodeValue(TreeNode* root)
    {
        if(nullptr==root) return;
        getTreeNodeValue(root->left);
        TreeNodeValList.push_back(root->val);
        getTreeNodeValue(root->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */