class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==right) return left;
        if(left==0||right==0) return 0;
        long int msb_l=(int)(log2(left));
        long int msb_r=(int)(log2(right));
        long int res=0;
        while(msb_l==msb_r){
            res+=1<<msb_l;
            left-=1<<msb_l;
            right-=1<<msb_l;
            if(left<=0||right<=0) break;
            msb_l=(long int)(log2(left));
            msb_r=(long int)(log2(right));
        }
        return res;
    }
};
