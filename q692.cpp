class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }
        
        auto comp=[&](pair<int,string>&p1,pair<int,string>&p2){
            if(p1.first==p2.first){
                return p1.second<p2.second;
            }
            else{
                return p1.first>p2.first;
            }
        };
        priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(comp)>pq(comp);
        unordered_map<string,int>::iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            pq.push({it->second,it->first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<string>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
