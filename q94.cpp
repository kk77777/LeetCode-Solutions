class Solution
{
    vector<int> in;

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == NULL)
        {
            return in;
        }
        inorderTraversal(root->left);
        in.push_back(root->val);
        inorderTraversal(root->right);
        return in;
    }
};