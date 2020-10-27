class Solution
{
public:
    Node *prev[6005];
    void fill(Node *curr, int level)
    {
        if (!curr)
            return;
        if (prev[level])
        {
            prev[level]->next = curr;
        }
        prev[level] = curr;
        fill(curr->left, level + 1);
        fill(curr->right, level + 1);
    }

    Node *connect(Node *root)
    {
        for (auto i : prev)
        {
            i = NULL;
        }
        fill(root, 0);
        return root;
    }
};