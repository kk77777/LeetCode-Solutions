class Solution
{
public:
    int findPivot(vector<int> &nums, int l, int h)
    {
        if (l > h)
            return -1;
        if (l == h)
            return l;
        int mid = l + (h - l) / 2;
        if (mid < h && nums[mid] > nums[mid + 1])
            return mid;
        if (mid > l && nums[mid] < nums[mid - 1])
            return mid - 1;
        if (nums[l] >= nums[mid])
            return findPivot(nums, l, mid - 1);
        return findPivot(nums, mid + 1, h);
    }

    int bSearch(vector<int> &nums, int target, int l, int h)
    {
        if (l > h)
            return -1;
        int mid = l + (h - l) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] > target)
            return bSearch(nums, target, l, mid - 1);
        return bSearch(nums, target, mid + 1, h);
    }

    int pBSearch(vector<int> &nums, int target)
    {
        int pivot = findPivot(nums, 0, nums.size() - 1);
        if (pivot == -1)
            return bSearch(nums, target, 0, nums.size() - 1);
        if (nums[pivot] == target)
            return pivot;
        if (nums[0] <= target)
            return bSearch(nums, target, 0, pivot - 1);
        return bSearch(nums, target, pivot + 1, nums.size() - 1);
    }

    int search(vector<int> &nums, int target)
    {
        return pBSearch(nums, target);
    }
};