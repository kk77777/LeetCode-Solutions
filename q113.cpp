class Solution {
    
   void findPaths(TreeNode*root,int targetSum,vector<int>&curr,vector<vector<int>>&ans){
        if(!root) return;
        curr.push_back(root->val);
        if(!root->left && !root->right && root->val==targetSum){
            ans.push_back(curr);
        }
       findPaths(root->left,targetSum-root->val,curr,ans);
       findPaths(root->right,targetSum-root->val,curr,ans);
       curr.pop_back();
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>curr;
        findPaths(root,targetSum,curr,ans);
        return ans;
    }
};
