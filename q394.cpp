class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        string ans;
        stack<int>nums;
        int num=0;
        for(char c:s){
            if(isdigit(c)){
                num=num*10+(c-'0');
            }
            else if(isalpha(c)){
                ans.push_back(c);
            }
            else if(c=='['){
                st.push(ans);
                nums.push(num);
                ans="";
                num=0;
            }
            else if(c==']'){
                string temp=ans;
                for(int i=0;i<nums.top()-1;i++){
                    ans+=temp;
                }
                ans=st.top()+ans;
                st.pop();
                nums.pop();
            }
        }
        return ans;
    }
};
