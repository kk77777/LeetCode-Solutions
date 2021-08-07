class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode*t=new TreeNode(val);
            return t;
        }
        TreeNode*iroot=root;
        while(root!=NULL){
            if(val<root->val){
                if(root->left){
                    root=root->left;
                }
                else{
                    TreeNode*temp=new TreeNode(val);
                    root->left=temp;
                    break;
                }
            }
            else{
                 if(root->right){
                    root=root->right;
                }
                else{
                    TreeNode*temp=new TreeNode(val);
                    root->right=temp;
                    break;
                }
            }
        }
        return iroot;
    }
};
