class Solution
{
public:
    int lis(vector<int> &li, int l, int h, int x)
    {
        while (l < h)
        {
            int mid = l + (h - l) / 2;
            if (li[mid] >= x)
            {
                h = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return h;
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 1;
        vector<int> li;
        li.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > li.back())
            {
                li.push_back(nums[i]);
            }
            else
            {
                int index = lis(li, 0, li.size() - 1, nums[i]);
                li[index] = nums[i];
            }
        }
        return li.size();
    }
};