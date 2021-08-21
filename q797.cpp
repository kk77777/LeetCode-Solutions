class Solution {
    
    void solve(vector<int>&temp,vector<vector<int>>&ans,int x,vector<vector<int>>&graph){
        if(x==graph.size()-1){
            ans.push_back(temp);
            return;
        }
        if(x==0){
            temp.push_back(x);
        }
        for(int i:graph[x]){
            temp.push_back(i);
            solve(temp,ans,i,graph);
            temp.pop_back();
        }
        return;
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>temp;
        vector<vector<int>>ans;
        solve(temp,ans,0,graph);
        return ans;
    }
};
