class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cnt = 0, maj = 0;
        for (int i : nums)
        {
            if (cnt == 0)
                maj = i;
            if (i == maj)
                cnt++;
            else
                cnt--;
        }
        return maj;
    }
};