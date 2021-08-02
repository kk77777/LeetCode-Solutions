class Solution {
    
    int dfs(vector<vector<int>>&grid,int x,int y,int id){
        if(x<0 || y<0 || x>=grid.size() || y>=grid.size() || grid[x][y]!=1) return 0;
        grid[x][y]=id;
        return 1+dfs(grid,x+1,y,id)+dfs(grid,x,y+1,id)+dfs(grid,x-1,y,id)+dfs(grid,x,y-1,id);
    }
    
public:
    int largestIsland(vector<vector<int>>& grid) {
        map<int,int>mp;
        int n=grid.size();
        int gId=2;
        int mxArea=1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int size=dfs(grid,i,j,gId);
                    mxArea=max(size,mxArea);
                    mp.insert({gId,size});
                    gId++;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    set<int>s;
                    int currArea=1;
                    s.insert(i>0?grid[i-1][j]:0);
                    s.insert(j>0?grid[i][j-1]:0);
                    s.insert(i<n-1?grid[i+1][j]:0);
                    s.insert(j<n-1?grid[i][j+1]:0);
                    
                    for(auto id:s){
                        currArea+=mp[id];
                    }
                    mxArea=max(currArea,mxArea);
                }
            }
        }
        return mxArea;
    }
};
