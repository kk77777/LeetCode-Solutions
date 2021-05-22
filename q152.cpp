class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int currMax = nums[0];
        int currMin = nums[0];
        int prevMax = nums[0];
        int prevMin = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            currMax = max(max(prevMax * nums[i], prevMin * nums[i]), nums[i]);
            currMin = min(min(prevMax * nums[i], prevMin * nums[i]), nums[i]);
            ans = max(currMax, ans);
            prevMax = currMax;
            prevMin = currMin;
        }
        return ans;
    }
};