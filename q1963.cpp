class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        int n=s.length();
        for(int i=0;i<n;i++){
            
                if(!st.empty() && st.top()=='[' && s[i]==']'){
                    st.pop();
                }
                if(s[i]=='['){
                    st.push(s[i]);
                }
            
        }
        if(st.size()%2==0)
            return st.size()/2;
        else
            return (st.size()+1)/2;
    }
};
