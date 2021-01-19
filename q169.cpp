class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maj=floor(nums.size()/2);
        for(int i:nums){
            mp[i]++;
            if(mp[i]>maj) return i;
        }
        return 0;
    }
};