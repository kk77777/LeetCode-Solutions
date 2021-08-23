class Solution {
    
    int findParent(int x,vector<int>&parent){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=findParent(parent[x],parent);
    }
    
    bool union_(int x,int y,vector<int>&parent,vector<int>&rank){
        int parentX=findParent(x,parent),parentY=findParent(y,parent);
        if(parentX==parentY) return false;
        if(rank[parentX]>rank[parentY]) parent[parentY]=parentX;
        else if(rank[parentY]>rank[parentX]) parent[parentX]=parentY;
        else parent[parentX]=parentY,rank[parentY]++;
        return true;
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n=edges.size()+1;
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto it:edges){
            if(!union_(it[0],it[1],parent,rank)) return it;
        }
        return {};
    }
};
