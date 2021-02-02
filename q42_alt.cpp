class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int l = 0, r = n - 1, res = 0, mxl = 0, mxr = 0;
        while (l <= r)
        {
            if (height[l] <= height[r])
            {
                if (height[l] >= mxl)
                    mxl = height[l];
                else
                    res += (mxl - height[l]);
                l++;
            }
            else
            {
                if (height[r] >= mxr)
                    mxr = height[r];
                else
                    res += (mxr - height[r]);
                r--;
            }
        }
        return res;
    }
};