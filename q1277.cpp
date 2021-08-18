class Solution {
    
    int solve(int x,int y, vector<vector<int>>&matrix, vector<vector<int>>&dp){
        int m=matrix.size(),n=matrix[0].size();
        if(x<0||x>=m||y<0||y>=n||matrix[x][y]!=1){
            return 0;
        }
        if(dp[x][y]!=-1) return dp[x][y];
        int r=solve(x,y+1,matrix,dp);
        int d=solve(x+1,y,matrix,dp);
        int dia=solve(x+1,y+1,matrix,dp);
        int ps=1+min(r,min(d,dia));
        return dp[x][y]=ps;
    }
    
    
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(),ans=0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]){
                    int cnt=solve(i,j,matrix,dp);
                    ans+=cnt;
                }
            }
        }
        return ans;
    }
};
