class Solution {
    
public:
    string rankTeams(vector<string>& votes) {
        int n=votes[0].size();
        string ans=votes[0];
     vector<vector<int>>freq(26,vector<int>(n));
        for(string s:votes){
            for(int pos=0;pos<n;pos++){
                freq[s[pos]-'A'][pos]++;
            }
        }
        
        sort(ans.begin(),ans.end(),[&](auto &x, auto &y){
            if(freq[x-'A']==freq[y-'A']){
            return x<y;
        }
        return (freq[x-'A']>freq[y-'A']);
        });
        return ans;
    }
};
