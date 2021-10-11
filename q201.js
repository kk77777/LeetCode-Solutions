/**
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
var rangeBitwiseAnd = function(left, right) {
    if(left==0 || right==0) return 0;
    if(left==right) return left;
    let l_msb=parseInt(Math.log(left)/Math.log(2));
    let r_msb=parseInt(Math.log(right)/Math.log(2));
    let res=0;
    while(l_msb==r_msb){
        res+=1<<l_msb;
        left-=1<<l_msb;
        right-=1<<l_msb;
        if(left<=0||right<=0) return res;
        l_msb=parseInt(Math.log(left)/Math.log(2));
        r_msb=parseInt(Math.log(right)/Math.log(2));
    }
    return res;
};
