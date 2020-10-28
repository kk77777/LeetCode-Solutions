class Solution
{
public:
    Node *getNextRight(Node *root)
    {
        Node *temp = root->next;
        while (temp)
        {
            if (temp->left)
            {
                return temp->left;
            }
            if (temp->right)
            {
                return temp->right;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    Node *connect(Node *root)
    {
        if (!root)
            return nullptr;
        if (root->left)
        {
            root->left->next = (root->right ? root->right : getNextRight(root));
        }
        if (root->right)
        {
            root->right->next = getNextRight(root);
        }
        connect(root->right);
        connect(root->left);
        return root;
    }
};