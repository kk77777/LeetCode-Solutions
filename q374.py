# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:


class Solution:
    def guessNumber(self, n: int) -> int:
        l = 1
        h = n
        while l <= h:
            mid = int(l + (h - l) / 2)
            vr = guess(mid)
            if vr == 0:
                return mid
            if vr == 1:
                l = mid + 1
            else:
                h = mid - 1
        return 0
