class Solution {
public:
    int calculate(string s) {
        char sign='+';
        stack<int>st;
         int ans=0;
       int temp=0;
        for(auto c=0;c<s.size();c++){
            if(isdigit(s[c])){
                temp=10*temp+(s[c]-'0');
            }
            if(!isdigit(s[c]) && !isspace(s[c])||c==s.size()-1){
                if(sign=='+'){
                    st.push(temp);
                }
                else if(sign=='-'){
                    st.push(-temp);
                }
                else{
                    int x;
                    if(sign=='*'){
                        x=st.top()*temp;
                    }
                    else{
                        if(sign=='/')
                            
                        x=st.top()/temp;
                    }
                    st.pop();
                    st.push(x);
                }
                sign=s[c];
                temp=0;
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
