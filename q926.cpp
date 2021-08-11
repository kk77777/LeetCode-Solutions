class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int i=0,n=s.length();
        while(i<n && s[i]!='1'){
            i++;
        }
        int c0=0,c1=0;
        for(i;i<n;i++){
            if(s[i]=='0'){
                c0++;
            }
            else{
                c1++;
            }
            if(c0>c1){
                c0=c1;
            }
        }
        return c0;
    }
};
