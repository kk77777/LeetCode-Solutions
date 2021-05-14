/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    void se(TreeNode *root, string &s)
    {
        if (!root)
        {
            s += "n ";
            return;
        }
        s += to_string(root->val) + " ";
        se(root->left, s);
        se(root->right, s);
    }
    string serialize(TreeNode *root)
    {
        string s = "";
        se(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *de(string &s, int &cp)
    {
        if (s[cp] == 'n')
        {
            cp += 2;
            return NULL;
        }
        string temp = "";
        while (s[cp] != ' ')
        {
            temp.push_back(s[cp++]);
        }
        cp++;
        TreeNode *root = new TreeNode(stoi(temp));
        root->left = de(s, cp);
        root->right = de(s, cp);
        return root;
    }

    TreeNode *deserialize(string data)
    {
        int cp = 0;
        return de(data, cp);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));