class Solution {
    
    vector<int>rightView(TreeNode*root,int level,int &mLevel,vector<int>&ans){
        if(root==NULL) return ans;
        if(mLevel<level){
            ans.push_back(root->val);
            mLevel=level;
        }
        rightView(root->right,level+1,mLevel,ans);
        rightView(root->left,level+1,mLevel,ans);
        return ans;
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        int mLevel=0;
        return rightView(root,1,mLevel,ans);
    }
};
