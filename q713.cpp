class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int s=0,e=0,prod=1,n=nums.size(),cnt=0;
        while(e<n){
            prod=prod*nums[e];
            while(s<n && prod>=k){
                prod/=nums[s];
                s++;
            }
            
            if(prod<k) cnt+=e-s+1;
            e++;
        }
        return cnt;
    }
};
