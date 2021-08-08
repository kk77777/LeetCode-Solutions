class Solution {

    void solve(vector<int>&nums,int l,int r,vector<vector<int>>&ans){
        if(l>=r){
            ans.push_back(nums);
        }
        else{
            for(int i=l;i<=r;i++){
                swap(nums[l],nums[i]);
                solve(nums,l+1,r,ans);
                swap(nums[l],nums[i]);
            }
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(nums,0,nums.size()-1,ans);
        return ans;
    }
};
