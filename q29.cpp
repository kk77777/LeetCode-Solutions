class Solution {
public:
    int divide(int dividend, int divisor) {
        cout<<INT_MIN<<" "<<INT_MAX<<"\n";
        
        if(dividend==INT_MIN && divisor==-1){
            return INT_MAX;
        } 
        if(dividend==INT_MIN && divisor==1){
            return INT_MIN;
        }
        unsigned int dividend2=abs(dividend);
        unsigned int divisor2=abs(divisor);
        int sign=(dividend<0)^(divisor<0)?-1:1;
        int res=0;
        while(dividend2>=divisor2){
            unsigned int tdivisor=divisor2;
            unsigned int tres=1;
            while(tdivisor<dividend2){
                tdivisor<<=1;
                tres<<=1;
            }
            if(tdivisor>dividend2){
                tdivisor>>=1;
                tres>>=1;
            }
            dividend2-=tdivisor;
            res+=tres;
        }
        return sign*res;
    }
};