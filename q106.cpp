class Solution
{
public:
    int cnt;
    unordered_map<int, int> index;
    TreeNode *build(vector<int> &post, int s, int e)
    {
        if (cnt < 0 || s > e)
            return NULL;
        int val = post[cnt--];
        int ind = index[val];
        TreeNode *temp = new TreeNode(val);
        temp->right = build(post, ind + 1, e);
        temp->left = build(post, s, ind - 1);

        return temp;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        cnt = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++)
        {
            index[inorder[i]] = i;
        }
        return build(postorder, 0, postorder.size() - 1);
    }
};