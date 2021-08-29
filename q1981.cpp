class Solution {
    int lim=INT_MAX;
    bool dp[75][5000]={false};
    void minDiff(int x,int sum,int target,int &md,vector<vector<int>>&mat){
        int m=mat.size();
        int n=mat[0].size();
        if(x==m){
            md=min(md,abs(target-sum));
            if(sum>=target){
                lim=min(lim,sum);
            }
            return;
        }
        
        for(int i=0;i<n;i++){
            sum+=mat[x][i];
            if(dp[x][sum]||sum>=lim){
                sum-=mat[x][i];
                continue;
            }
            minDiff(x+1,sum,target,md,mat);
            dp[x][sum]=true;
            sum-=mat[x][i];
        }
        return;
    }
    
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int md=INT_MAX;
        minDiff(0,0,target,md,mat);
        return md;
    }
};
