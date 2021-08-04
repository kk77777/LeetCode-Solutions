class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long l=1,h=100000,ans=-1;
        while(l<=h){
            long long m=(l+h)/2;
            long long temp=2*m*(m+1)*(2*m+1);
            if(temp<neededApples){
                l=m+1;
            }
            else{
                ans=m;
                h=m-1;
            }
        }
        return 8*ans;
    }
};
