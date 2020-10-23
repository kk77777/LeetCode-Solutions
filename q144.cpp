class Solution
{
public:
    vector<int> pre;
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == NULL)
        {
            return pre;
        }

        pre.push_back(root->val);

        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return pre;
    }
};