class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<int>time(n);
        for(int i=0;i<n;i++){
            time[i]=ceil((double)dist[i]/(double)speed[i]);
        }
        sort(time.begin(),time.end());
        int i=0;
        for(i=0;i<n;i++){
            if(time[i]<=i){
                break;
            }
        }
        return i;
    }
};
