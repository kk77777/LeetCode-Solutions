import math


class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ll = floor(math.log10(low)+1)
        hl = floor(math.log10(high)+2)
        res = []
        for i in range(ll, hl):
            for j in range(10-i):
                no = 0
                for k in range(j, j+i):
                    no = no*10+k+1
                if low <= no <= high:
                    res.append(no)
        return res
