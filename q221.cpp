class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n=matrix.size();
        int m=matrix[0].size();
        
        int ans=0,flag=0;
        vector<vector<int>>res(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            res[i][0]=matrix[i][0]-'0';
            flag=max(flag,res[i][0]);
        }
        for(int j=0;j<m;j++){
            res[0][j]=matrix[0][j]-'0';
            flag=max(flag,res[0][j]);
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]=='0') 
                    res[i][j]=0;
                else 
                    res[i][j]=1+min(res[i-1][j-1],min(res[i-1][j],res[i][j-1]));
                
                if(ans<res[i][j]) ans=res[i][j];
            }
            
        }
  
        return max(ans*ans,flag);
    }
};