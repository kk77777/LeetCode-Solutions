class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(string i:strs){
            string x=i;
            sort(x.begin(),x.end());
            mp[x].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto it=mp.begin();it!=mp.end();it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};
