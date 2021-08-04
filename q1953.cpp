class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long n=milestones.size();
        int mx=INT_MIN;
        long long sum=0,ans=0;
        for(auto i=0;i<n;i++){
            mx=max(mx,milestones[i]);
            sum+=milestones[i];
        }
        long long rst=sum-mx;
        if(mx>rst){
            ans=2*rst+1;
        }
        else{
            ans=sum;
        }
        return ans;
    }
};
