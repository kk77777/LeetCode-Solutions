class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min_=nums[0],max_=nums[0];
        for(int i=1;i<nums.size();i++){
            min_=min(nums[i],min_);
            max_=max(nums[i],max_);
        }
        int ans=1;
        for(int i=2;i<=min_;i++){
            if(min_%i==0 && max_%i==0){
                ans=i;
            }
        }
        return ans;
    }
};
