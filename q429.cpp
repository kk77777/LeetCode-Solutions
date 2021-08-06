class Solution {
    int rLevel=-1;
    void solve(Node*root,int level,vector<vector<int>>&v){
        if(root==NULL) return;
        if(rLevel<level){
            rLevel++;
            int n=v.size();
            v.resize(n+1);
        }
        v[level].push_back(root->val);
        for(auto i:root->children){
            solve(i,level+1,v);
        }
        
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>v;
        solve(root,0,v);
        return v;
    }
};
