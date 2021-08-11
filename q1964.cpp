class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int>dp(n,INT_MAX);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int pos=upper_bound(dp.begin(),dp.end(),obstacles[i])-dp.begin();
            dp[pos]=min(dp[pos],obstacles[i]);
            ans[i]=pos+1;
        }
        return ans;
    }
};
