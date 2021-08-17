class Solution {
    void solve(TreeNode*root,int cm,int &cnt){
        if(root==NULL) return;
        if(root->val>=cm){
            cnt++;
            cm=max(cm,root->val);
        }
        solve(root->left,cm,cnt);
        solve(root->right,cm,cnt);
        return;
    }
public:
    int goodNodes(TreeNode* root) {
        int cm=root->val;
        int cnt=0;
        solve(root,cm,cnt);
        return cnt;
    }
};
