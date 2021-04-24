class Solution {
public:
    
    TreeNode*constructBST(vector<int>&pre,int &pi,int key,int mn,int mx,int n){
        if(pi>=n) return NULL;
        TreeNode*root=NULL;
        if(key>mn && key<mx){
            root=new TreeNode(key);
            pi++;
            if(pi<n){
                root->left=constructBST(pre,pi,pre[pi],mn,key,n);
            }
            if(pi<n){
                root->right=constructBST(pre,pi,pre[pi],key,mx,n);
            }
        }
        return root;
        
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        if(n==0) return NULL;
        int pi=0;
        return constructBST(preorder,pi,preorder[0],INT_MIN,INT_MAX,n);
    }
};
