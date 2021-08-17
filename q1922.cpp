class Solution {
    long long mod=1e9+7;
    long long power(long long x,long long y){
        if(y==0) return 1;
        long long p=power(x,y/2);
        p*=p;
        p%=mod;
        if(y%2!=0){
            p*=x;
        }
        p%=mod;
        return p;
    }
    
public:
    int countGoodNumbers(long long n) {
        long long odd=n/2;
        long long even=n/2+n%2;
        return (power(5,even)*power(4,odd))%mod;
    }
};
