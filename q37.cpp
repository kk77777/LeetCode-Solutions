class Solution {
public:
    
    bool isSafe(vector<vector<char>>&board,int x,int y,int num){
        for(int row=0;row<9;row++){
            if(board[row][y]==num) return false;
        }
        for(int col=0;col<9;col++){
            if(board[x][col]==num) return false;
        }
        int rs=x/3*3,cs=y/3*3;
        for(int row=0;row<3;row++){
            for(int col=0;col<3;col++){
                if(board[row+rs][col+cs]==num) return false;
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>>&board,int x,int y){
        
        if(y>=9){
            x++;
            y=0;
        }
        if(x>=9) return true;
        
        if(board[x][y]!='.') return solve(board,x,y+1);
        else{
            for(int num='1';num<='9';num++){
            if(isSafe(board,x,y,num)){
                board[x][y]=num;
                if(solve(board,x,y+1))return true;
            
           
                board[x][y]='.';
                }
            }
            return false;
        }
        
        return true;
    }
        
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
        return;
    }
};