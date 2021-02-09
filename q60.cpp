class Solution {
public:
    
    bool solve(string gs,string ts,int &cnt,int n,int k,string &ans){
        
        if(gs.length()==0){
            cnt++;
            if(cnt==k){
                ans=ts;
                return true;
            }
            return false;
        }
        
        
        for(int i=0;i<gs.length();i++){
            string temp=gs;
            temp.erase(i,1);
            if(solve(temp,ts+gs[i],cnt,n,k,ans)){
                return true;
            }
        }
        return false;
    }
    
    string getPermutation(int n, int k) {
        string gs="";
        string ts="";
        string ans;
        for(int i=1;i<=n;i++){
            gs+=(i+48);
        }
        int cnt=0;
        solve(gs,ts,cnt,n,k,ans);
        return ans;
    }
};