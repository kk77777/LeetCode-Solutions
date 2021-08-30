class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1,maxArea=0,mxl=0,mxr=0;
        while(l<=r){
           int currArea=min(height[l],height[r])*(r-l);
            maxArea=max(maxArea,currArea);
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxArea;
    }
};
