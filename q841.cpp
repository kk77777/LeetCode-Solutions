class Solution {
    
    void dfs(int x,vector<bool>&vis,vector<vector<int>>&rooms){
        vis[x]=true;
        for(int i:rooms[x]){
            if(vis[i]) continue;
            dfs(i,vis,rooms);
        }
        return;
    }
    
    
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n+1,false);
        vis[0]=true;
        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
            dfs(i,vis,rooms);
        }
        return true;
    }
};
