class Solution {
public:
    bool isCompleteTree(TreeNode* root) {

        if (!root)
        {
            return true;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool leaf = false; //是否必须为叶子节点

        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            if (!node->left && node->right) //仅有右子节点，无左子节点
            {
                return false;
            }

            if (leaf) //前面出现过无右子节点的 (只有左 或 左右都没有的) 后续所有节点必须为叶子节点
            {
                if (node->left || node->right) //非叶子节点
                {
                    return false;
                }
            }

            if (node->left)
            {
                q.push(node->left);
            }

            if (node->right)
            {
                q.push(node->right);
            }
            else //右为空 则后续层的节点必须为叶子节点
            {
                leaf = true; 
            }
        }

        return true;
    }
};