class Solution {
public:
    string addStrings(string num1, string num2) {
        int n=num1.length()-1;
        int m=num2.length()-1;
        int sum=0;
        string ans="";
        int carry=0;
        while(n>=0 || m>=0||carry>0){
            if(n>=0){
                sum+=(num1[n]-'0');
                n--;
            }
            if(m>=0){
                sum+=(num2[m]-'0');
                m--;
            }
            if(carry>0){
                sum+=carry;
                carry=0;
            }
            carry=sum/10;
            ans+=(sum%10+'0');
            sum=0;
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
