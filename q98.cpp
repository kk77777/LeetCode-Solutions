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
class Solution
{
public:
    bool checkForBST(TreeNode *root, long long int mn, long long int mx)
    {
        if (root == NULL)
            return true;
        if (root->val < mn || root->val > mx)
        {
            return false;
        }
        if (root->left == NULL && root->right == NULL)
            return true;
        return ((checkForBST(root->left, mn, (long long)root->val - 1)) && (checkForBST(root->right, (long long)root->val + 1, mx)));
    }

    bool isValidBST(TreeNode *root)
    {
        return checkForBST(root, INT_MIN, INT_MAX);
    }
};