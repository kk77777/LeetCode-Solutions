class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        rows=len(matrix)
        cols=len(matrix[0])
        flag,ans=0,0
        res = [[0 for i in range(cols)] for j in range(rows)]
        print(res)
        for i in range(0,rows):
            res[i][0]=int(matrix[i][0])
            flag=max(res[i][0],flag)
            
        for j in range(0,cols):
            res[0][j]=int(matrix[0][j])
            flag=max(res[0][j],flag)
            
        for i in range(1,rows):
            for j in range(1,cols):
                if(matrix[i][j]=='0'):
                    res[i][j]=0
                else:
                    res[i][j]=1+min(res[i-1][j-1],res[i-1][j],res[i][j-1])
                if ans<res[i][j]:
                    ans=res[i][j]
        
        return max(ans*ans,flag)
