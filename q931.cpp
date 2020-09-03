class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &A)
    {
        int n = A.size();
        int m = A[0].size();

        if (n == 0)
            return 0;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j == 0)
                {
                    A[i][j] += min(A[i - 1][j], A[i - 1][j + 1]);
                }
                else if (j == m - 1)
                {
                    A[i][j] += min(A[i - 1][j], A[i - 1][j - 1]);
                }
                else
                {
                    A[i][j] += min(A[i - 1][j], min(A[i - 1][j - 1], A[i - 1][j + 1]));
                }
            }
        }
        int ans = INT_MAX;
        for (int j = 0; j < m; j++)
        {
            ans = min(ans, A[m - 1][j]);
        }
        return ans;
    }
};