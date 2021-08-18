class Solution {
    
    int solve(int n,int x,vector<vector<int>>&dp){
        if(n==0) return 1;
        if(x>4) return 0;
        if(dp[n][x]!=-1) return dp[n][x];
        return dp[n][x]=solve(n-1,x,dp)+solve(n,x+1,dp);
    }
    
public:
    int countVowelStrings(int n) {
        vector<vector<int>>dp(n+1,vector<int>(5,-1));
        return solve(n,0,dp);
    }
};
