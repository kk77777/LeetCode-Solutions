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
    vector<TreeNode *> solve(int n)
    {
        if (n == 1)
        {
            return {new TreeNode(0)};
        }
        n--;
        vector<TreeNode *> ans;
        vector<TreeNode *> left, right;
        for (int i = 1; i < n; i += 2)
        {
            left = solve(i);
            right = solve(n - i);

            for (TreeNode *j : left)
            {
                for (TreeNode *k : right)
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = j;
                    root->right = k;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (n == 1)
        {
            return {new TreeNode(0)};
        }
        if (n % 2 == 0)
        {
            return {};
        }
        if (n == 3)
        {
            return {new TreeNode(0, new TreeNode(0), new TreeNode(0))};
        }

        return solve(n);
    }
};