class Solution {
    
    void per(vector<string>&nums,int s,int e,string temp,vector<string>&ans){
        if(s==e){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums[s].size();i++){
            per(nums,s+1,e,temp+nums[s][i],ans);
        }
        
    }
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        vector<string>nums;
        if(digits.size()==0) return ans; 
        string givenComb[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(int i=0;i<digits.size();i++){
            nums.push_back(givenComb[digits[i]-'0']);
        }
        per(nums,0,nums.size(),"",ans);
        return ans;
    }
};
