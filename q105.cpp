class Solution
{
public:
    unordered_map<int, int> index;
    int cnt = 0;
    TreeNode *build(vector<int> &pre, int s, int e)
    {
        if (e < s)
            return NULL;
        int val = pre[cnt++];
        int ind = index[val];
        TreeNode *temp = new TreeNode(val);
        temp->left = build(pre, s, ind - 1);
        temp->right = build(pre, ind + 1, e);

        return temp;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            index[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1);
    }
};