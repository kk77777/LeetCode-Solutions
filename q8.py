class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.strip()
        if len(s) == 0:
            return 0
        flag = 0
        st = 0
        res = ""

        if s[st] == '-':
            if len(s) == 1:
                return 0
            flag = 1
            st += 1
        elif s[st] == '+':
            if len(s) == 1:
                return 0
            st += 1
        if not s[st].isdigit():
            return 0
        for c in s[st:]:
            if not c.isdigit():
                break
            res += c
        ans = 0
        res = res if not flag else '-'+res
        ans = int(res)
        if ans > pow(2, 31)-1:
            ans = pow(2, 31)-1
        elif ans < -pow(2, 31):
            ans = -pow(2, 31)
        return ans
