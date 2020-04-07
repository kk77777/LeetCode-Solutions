class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int mid = nums.size() / 2;
        while (mid > 0 && mid < nums.size())
        {
            if (mid == 0 && nums[0] > nums[1])
                return 0;
            if (mid == nums.size() - 1 && nums[nums.size() - 1] > nums[nums.size() - 2])
                return nums.size() - 1;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            else if (nums[mid] < nums[mid - 1])
                mid--;
            else
                mid++;
        }
        return mid;
    }
};