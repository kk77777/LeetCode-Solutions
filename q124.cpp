class Solution {
public:
    
    int solve(TreeNode*root,int &res){
        if(root==NULL) return 0;
        int ls=solve(root->left,res);
        int rs=solve(root->right,res);
        int mx1=max(max(ls,rs)+root->val,root->val);
        int mx2=max(mx1,ls+rs+root->val);
        res=max(res,mx2);
        return mx1;
    }
    
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int res=INT_MIN;
        solve(root,res);
        return res;
    }
};
