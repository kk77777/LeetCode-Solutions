class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        vector<string>prefix(words.size());
        prefix[0]=words[0];
        for(int i=1;i<words.size();i++){
            prefix[i]=prefix[i-1]+words[i];
        }
        for(int i=0;i<prefix.size();i++){
            if(s.compare(prefix[i])==0){
                return true;
            }
        }
        return false;
    }
};
