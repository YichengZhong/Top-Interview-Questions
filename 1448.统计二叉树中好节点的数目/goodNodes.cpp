class Solution {
public:
    int node_count = 0;

    //参数max_value: 从根节点到node节点路径(不含node)上的最大值
    void dfs(TreeNode* node, int max_value)
    {
        if (node == nullptr)
        {
            return;
        }

        if (max_value <= node->val)
        {
            ++node_count;
        }

        max_value = max(max_value, node->val);

        dfs(node->left, max_value);
        dfs(node->right, max_value);
    }

    int goodNodes(TreeNode* root) 
    {
        node_count = 0;
        dfs(root, root->val);
        return node_count;
    }
};
