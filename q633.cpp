class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i=0;i<=sqrt(c);i++){
            int temp=sqrt(c-i*i);
            if(temp*temp==c-i*i) return true;
        }
        return false;
    }
};
