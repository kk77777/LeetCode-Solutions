class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        prev, cnt = 0, 0
        for plot in flowerbed:
            if plot == 1:
                if prev == 1:
                    cnt -= 1
                else:
                    prev = 1
            else:
                if prev == 1:
                    prev = 0
                else:
                    cnt += 1
                    prev = 1
        return cnt >= n
