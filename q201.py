class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        if left==0 or right==0:
            return 0;
        l_msb=int(math.log(left,2))
        r_msb=int(math.log(right,2))
        res=0
        while(l_msb==r_msb):
            res+=1<<l_msb
            left-=1<<l_msb
            right-=1<<l_msb
            if(left<=0 or right<=0):
                return res
            l_msb=int(math.log(left,2))
            r_msb=int(math.log(right,2))
        return res
