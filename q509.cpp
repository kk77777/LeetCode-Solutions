class Solution
{
public:
    int fib(int N)
    {
        vector<int> f(N + 1, 0);
        if (N < 2)
        {
            return N;
        }
        f[0] = 0;
        f[1] = 1;
        for (int i = 2; i <= N; i++)
        {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[N];
    }
};