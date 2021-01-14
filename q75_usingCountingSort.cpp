class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int x = 0, y = 0, z = 0;
        for (int i : nums)
        {
            if (i == 0)
                x++;
            if (i == 1)
                y++;
            if (i == 2)
                z++;
        }
        int i = 0;
        while (x != 0)
        {
            nums[i] = 0;
            i++;
            x--;
        }
        while (y != 0)
        {
            nums[i] = 1;
            i++;
            y--;
        }
        while (z != 0)
        {
            nums[i] = 2;
            i++;
            z--;
        }
    }
};