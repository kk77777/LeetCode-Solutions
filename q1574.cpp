class Solution
{
public:
    int findLengthOfShortestSubarray(vector<int> &arr)
    {
        int n = arr.size();
        int j;
        for (j = n - 1; j > 0; j--)
        {
            if (arr[j - 1] > arr[j])
                break;
        }
        int res = j;
        if (j == 0)
            return 0;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && arr[i - 1] > arr[i])
                break;
            while (j < n && arr[i] > arr[j])
                ++j;
            res = min(res, j - i - 1);
        }
        return res;
    }
};