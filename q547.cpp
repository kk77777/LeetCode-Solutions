class Solution {
    
    void dfs(int x,vector<bool>&vis,vector<vector<int>>&isConnected){
        vis[x]=true;
        for(int i=0;i<isConnected[x].size();i++){
            if(i==x || vis[i]||isConnected[x][i]==0) continue;
            dfs(i,vis,isConnected);
        }
        return;
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>vis(n+1,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,isConnected);
            }
        }
        return cnt;
    }
};
