class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>::iterator x=lower_bound(nums.begin(),nums.end(),target);
        vector<int>::iterator y=lower_bound(nums.begin(),nums.end(),target+1);
        if(x!=nums.end() && *x==target){
            int res1=x-nums.begin();
            int res2=y-nums.begin()-1;
            return {res1,res2};
        }
        return {-1,-1};
    }
};
