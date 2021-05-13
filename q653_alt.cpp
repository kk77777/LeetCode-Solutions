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
    void fillLeft(TreeNode *root, stack<TreeNode *> &s1)
    {
        while (root)
        {
            s1.push(root);
            root = root->left;
        }
    }
    void fillRight(TreeNode *root, stack<TreeNode *> &s2)
    {
        while (root)
        {
            s2.push(root);
            root = root->right;
        }
    }

    bool findTarget(TreeNode *root, int k)
    {
        stack<TreeNode *> s1, s2;
        fillLeft(root, s1);
        fillRight(root, s2);
        TreeNode *l = s1.top();
        TreeNode *h = s2.top();
        while (l->val < h->val)
        {
            if (l->val + h->val == k)
                return true;
            else if (l->val + h->val < k)
            {
                TreeNode *temp = s1.top();
                s1.pop();
                fillLeft(temp->right, s1);
                l = s1.top();
            }
            else
            {
                TreeNode *temp = s2.top();
                s2.pop();
                fillRight(temp->left, s2);
                h = s2.top();
            }
        }
        return false;
    }
};