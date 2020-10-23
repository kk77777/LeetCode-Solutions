class Solution
{
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == NULL)
        {
            return false;
        }
        else
        {
            bool ans = false;

            int sub = sum - root->val;
            if (sub == 0 && root->left == NULL && root->right == NULL)
                return true;
            if (root->left)
            {
                ans = ans || hasPathSum(root->left, sub);
            }
            if (root->right)
            {
                ans = ans || hasPathSum(root->right, sub);
            }
            return ans;
        }
    }
};