class Solution {
public:
    
    bool isPal(string s,int l,int h){
        while(l<h){
            if(s[l]!=s[h]) return false;
            l++;
            h--;
        }
        return true;
    }
    
    void solve(string s,vector<string>&t,vector<vector<string>>&ans,int start,int n){
        if(start>=n){
            ans.push_back(t);
            return;
        }   
        for(int i=start;i<n;i++){
            if(isPal(s,start,i)){
                t.push_back(s.substr(start,i-start+1));
                solve(s,t,ans,i+1,n);
                t.pop_back();
            }
        }
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<string>t;
        vector<vector<string>>ans;
        int n=s.length();
        if(n==0) return ans;
        solve(s,t,ans,0,n);
        return ans;
    }
};