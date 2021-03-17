class Solution
{
public:
    string intToRoman(int k)
    {
        string ans;
        int nums[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string ro[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int i = 12;
        while (k > 0)
        {
            int d = k / nums[i];
            k = k % nums[i];
            while (d--)
            {
                ans += ro[i];
            }
            i--;
        }
        return ans;
    }
};