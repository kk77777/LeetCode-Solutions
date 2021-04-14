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
class Solution {
public:
    
    bool isIdentical(TreeNode *r1, TreeNode *r2)
    {
        if (!r1 && !r2)
            return true;
        if (!r1)
            return false;
        if (!r2)
            return false;
        if (r1->val != r2->val)
            return false;
        bool ls = isIdentical(r1->left, r2->left);
        bool rs = isIdentical(r1->right, r2->right);
        if (!ls || !rs)
            return false;
        return true;
    }
    
    bool isSubtree(TreeNode* t, TreeNode* s) {
        
        if (!s)
            return true;

        if (!t)
            return false;
        queue<TreeNode *> q;
        q.push(t);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->val == s->val)
            {
                if (isIdentical(temp, s))
                    return true;
            }
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        return false;
    }
};