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
    
    void inOrder(TreeNode*root,vector<int>&v){
        if(root==NULL) return;
        inOrder(root->left,v);
        v.push_back(root->val);
        inOrder(root->right,v);
    }
    
    TreeNode* construct(vector<int>&v,int s,int e){
        if(s>e) return NULL;
        int mid=(s+e)/2;
        TreeNode*newRoot=new TreeNode(v[mid]);
        newRoot->left=construct(v,s,mid-1);
        newRoot->right=construct(v,mid+1,e);
        return newRoot;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        inOrder(root,v);
        return construct(v,0,v.size()-1);   
    }
};
