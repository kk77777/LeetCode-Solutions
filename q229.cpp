class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        vector<int> ans;
        int maj = floor(nums.size() / 3);
        for (int i : nums)
        {
            mp[i]++;
        }
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            if (it->second > maj)
                ans.push_back(it->first);
        }
        return ans;
    }
};