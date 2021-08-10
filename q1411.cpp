class Solution {
public:
    int numOfWays(int n) {
        long mod = (long) 1e9 + 7;
        long pat1 = 6;
        long pat2 = 6;
        for (int i=1;i<n;i++) {
            long x = pat1 * 3 + pat2 * 2;
            long y = pat1 * 2 + pat2 * 2;
            pat1 = x % mod;
            pat2 = y % mod;
        }
        return (int) ((pat1 + pat2) % mod);
    }
};
