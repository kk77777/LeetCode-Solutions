class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> ans;
        int maj = floor(nums.size() / 3);
        int cnt1 = 0, cnt2 = 0, num1 = 0, num2 = 0;
        for (int i : nums)
        {
            if (i == num1)
                cnt1++;
            else if (i == num2)
                cnt2++;
            else if (cnt1 == 0)
            {
                num1 = i;
                cnt1++;
            }
            else if (cnt2 == 0)
            {
                num2 = i;
                cnt2++;
            }

            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = cnt2 = 0;
        for (int i : nums)
        {
            if (i == num1)
                cnt1++;
            else if (i == num2)
                cnt2++;
        }
        if (cnt1 > maj)
            ans.push_back(num1);
        if (cnt2 > maj)
            ans.push_back(num2);
        return ans;
    }
};