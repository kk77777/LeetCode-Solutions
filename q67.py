class Solution:
    def addBinary(self, a: str, b: str) -> str:
        i = -1
        carry = 0
        res = ""
        al, bl = -len(a), -len(b)
        while i >= al or i >= bl:
            a_bit = int(a[i]) if i >= al else 0
            b_bit = int(b[i]) if i >= bl else 0
            sum_bit = a_bit+b_bit+carry
            carry = sum_bit//2
            res = str(sum_bit % 2)+res
            i -= 1
        print(carry)
        return '1'+res if carry else res
