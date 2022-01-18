class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        dir = [[0, 1], [-1, 0], [0, -1], [1, 0]]
        x, y = 0, 0
        r = 0
        for i in instructions:
            if i == 'L':
                r = (r+1) % 4
            elif i == 'R':
                r = (r+3) % 4
            else:
                x += dir[r][0]
                y += dir[r][1]
        return (x == 0 and y == 0) or r != 0
