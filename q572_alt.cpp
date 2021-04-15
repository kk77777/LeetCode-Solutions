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
	void inOrder(TreeNode *root, string &in)
	{
		if (root == NULL)
		{
			in.push_back('$');
			return;
		}
		inOrder(root->left, in);
		in.push_back((char)root->val + '0');
		inOrder(root->right, in);
	}

	void preOrder(TreeNode *root, string &pre)
	{
		if (root == NULL)
		{
			pre.push_back('$');
			return;
		}
		pre.push_back((char)root->val + '0');
		preOrder(root->left, pre);
		preOrder(root->right, pre);
	}

	bool isSubtree(TreeNode *t, TreeNode *s)
	{
		if (!s)
			return true;
		if (!t)
			return false;
		string it, is, pt, ps;
		inOrder(t, it);
		inOrder(s, is);
		int found = it.find(is);
		if (found == string::npos)
			return false;
		preOrder(t, pt);
		preOrder(s, ps);
		found = pt.find(ps);
		if (found == string::npos)
			return false;
		return true;
	}
};