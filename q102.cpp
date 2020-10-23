class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> v;
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == NULL)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                v.push_back(temp->val);
                if (temp->left != NULL)
                {
                    q.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    q.push(temp->right);
                }
            }
            ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};