class Solution {
    
    void dfs(int x,int y,vector<vector<int>>&grid2){
        int m=grid2.size(),n=grid2[0].size();
        if(x<0 || x>=m || y<0 || y>=n || grid2[x][y]==0) return;
        grid2[x][y]=0;
        dfs(x+1,y,grid2);
        dfs(x-1,y,grid2);
        dfs(x,y+1,grid2);
        dfs(x,y-1,grid2);
    }
    
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid2.size(),n=grid2[0].size(),cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1 && grid1[i][j]==0){
                    dfs(i,j,grid2);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1){
                    cnt++;
                    dfs(i,j,grid2);
                }
            }
        }
        return cnt;
    }
};
