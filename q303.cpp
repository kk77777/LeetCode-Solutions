class NumArray {
public:
    vector<int>dp;
    NumArray(vector<int>& nums) {
        int sum=nums[0];
        dp.push_back(sum);
        for(int i=1;i<nums.size();i++){
            dp.push_back(nums[i]+sum);
            sum+=nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return left==0?dp[right]:dp[right]-dp[left-1];
    }
};

