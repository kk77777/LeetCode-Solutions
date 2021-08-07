class Solution {
    
    bool isOperator(string op){
        if(op=="+"||op=="-"||op=="*"||op=="/"){
            return true;
        }
        return false;
    }
    
    int eval(int x,int y, char op){
        switch(op){
            case '+': return x+y;
            case '-': return y-x;
            case '*': return y*x;
            case '/': return y/x;
        }
        return 0;
    }
    
    
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(int i=0;i<tokens.size();i++){
            if(isOperator(tokens[i])){
                int x=s.top();
                s.pop();
                int y=s.top();
                s.pop();
                char c=tokens[i][0];
                int res=eval(x,y,c);
                s.push(res);
            }
            else{
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
        return 0;
    }
};
