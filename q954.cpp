class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mp;
        for(int i:arr){
            mp[i]++;
        }
        for(int i:arr){
            if(mp[i]==0) continue;
            if(i<0 && i%2!=0) return false;
            int j=i>0?i*2:i/2;
            if(mp[j]==0) return false;
            mp[i]--;
            mp[j]--;
        }
        return true;
    }
};
