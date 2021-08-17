class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()==0||t.length()==0||s.length()<t.length()) return "";
        unordered_map<char,int>x,y;
        int start=0,end=0;
        for(char i:t){
            y[i]++;
        }
        for(start=0;start<s.size();start++){
            if(y.find(s[start])!=y.end()){
                break;
            }
        }
        end=start;
        int cnt=0;
        while(end<s.size()){
            if(x[s[end]]<y[s[end]]){
                cnt++;
            }
            x[s[end]]++;
           
            if(cnt==t.size()){
                break;
            }
             end++;
        }
        if(cnt<t.size()) return "";
         while(x[s[start]]>y[s[start]]){
                x[s[start]]--;
                start++;
            }
        int ml=end-start+1;
        string ans=s.substr(start,ml);
        if(end==s.size()) return ans;
        while(end<s.size()){
            x[s[start]]--;
            char prev=s[start];
            start++;
            end++;
            while(end<s.size() && s[end]!=prev){
                x[s[end]]++;
                end++;
            }
            if(end==s.size()) return ans;
            x[s[end]]++;
            while(x[s[start]]>y[s[start]]){
                x[s[start]]--;
                start++;
            }
            int cl=end-start+1;
            if(cl<ml){
                ans=s.substr(start,cl);
                ml=cl;
            }
        }
        
        return ans;
    }
};
