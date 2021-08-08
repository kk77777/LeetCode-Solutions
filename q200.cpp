class Solution {
public:
    
    pair<int,int>pd[4]={{1,0},{-1,0},{0,1},{0,-1}};
    
    void dfs(int x,int y,vector<vector<char>>&grid){
        if(x<0||y<0||x>=grid.size()||y>=grid[0].size()||grid[x][y]=='0') return;
        grid[x][y]='0';
        for(auto d:pd){
            dfs(x+d.first,y+d.second,grid);
        }
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='0') continue;
                cnt++;
                dfs(i,j,grid);
            }
        }
        return cnt;
    }
};
