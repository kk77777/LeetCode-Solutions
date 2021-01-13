class Solution
{
public:
    unordered_map<int, int> mp;
    int findDuplicate(vector<int> &nums)
    {
        for (int i = 0; i <= nums.size(); i++)
        {
            mp[nums[i]]++;
            if (mp[nums[i]] != 1)
            {
                return nums[i];
            }
        }
        return 0;
    }
};