class Solution
{
public:
    vector<int> getRow(int n)
    {
        vector<int> v;
        long long int k;
        for (int i = 0; i <= n; i++)
        {
            if (i == 0 || i == n)
            {
                k = 1;
            }
            else
            {
                k = k * (n - i + 1) / i;
            }
            v.push_back(k);
        }
        return v;
    }
};