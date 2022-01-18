class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        def solve(points):
            points.sort()
            res = []
            flag = 1
            a, b = points[0][0], points[0][1]
            for x in range(1, len(points)):
                if b >= points[x][0]:
                    a = max(a, points[x][0])
                    b = min(b, points[x][1])
                else:
                    res.append([a, b])
                    a = points[x][0]
                    b = points[x][1]
            last_a, last_b = 0, 0
            if len(res):
                last_a, last_b = res[-1]
            res.append([a, b]) if len(res) == 0 or last_a != a else None
            return len(res)
        return solve(points)
