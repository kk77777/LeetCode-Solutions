import math


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:

        if len(piles) == h:
            return max(piles)

        def timeTaken(speed: int) -> int:
            time = 0
            for item in piles:
                time += math.ceil(item/speed)
            return time

        mx = max(piles)
        mn = 1
        res = mx

        while mn <= mx:
            mid = math.ceil((mn+mx)/2)
            time = timeTaken(mid)
            if time <= h:
                res = mid
                mx = mid-1
            else:
                mn = mid+1
        return res
