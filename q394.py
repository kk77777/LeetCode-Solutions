class Solution:
    def decodeString(self, s: str) -> str:
        nums=[]
        st=[]
        num=0
        ans=""
        for c in s:
            if c.isdigit():
                num=num*10+int(c)  
            
            elif c.isalpha():
                ans+=c
            elif c=='[':
                st.append(ans)
                ans=""
                nums.append(num)
                num=0
            elif c==']':
                temp=ans
                ans=temp*nums[-1]
                nums.pop()
                ans=st[-1]+ans
                st.pop()
        return ans
