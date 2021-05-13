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
    void inorderFill(TreeNode *root, vector<int> &v)
    {
        if (root == NULL)
            return;
        inorderFill(root->left, v);
        v.push_back(root->val);
        inorderFill(root->right, v);
    }

    bool findTarget(TreeNode *root, int k)
    {
        if (root == NULL)
            return false;
        vector<int> v;
        inorderFill(root, v);
        int l = 0, h = v.size() - 1;
        while (l < h)
        {
            if (v[l] + v[h] < k)
            {
                l++;
            }
            else if (v[l] + v[h] > k)
            {
                h--;
            }
            else
                return true;
        }
        return false;
    }
};