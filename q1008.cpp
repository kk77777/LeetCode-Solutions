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
    
    TreeNode*constructBST(vector<int>&preorder,int &pi,int s,int e,int n){
        if(pi>=n||s>e) return NULL;
        TreeNode*root=new TreeNode(preorder[pi++]);
        if(s==e) return root;
        int i;
        for(i=s;i<=e;i++){
            if(preorder[i]>root->val) break;
        }
        root->left=constructBST(preorder,pi,pi,i-1,n);
        root->right=constructBST(preorder,pi,i,e,n);
        return root;
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        if(n==0) return NULL;
        int pi=0;
        return constructBST(preorder,pi,0,n-1,n);
    }
};
