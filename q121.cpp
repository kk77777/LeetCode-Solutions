class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minm = INT_MAX, maxPr = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            minm = min(minm, prices[i]);
            maxPr = max(maxPr, prices[i] - minm);
        }
        return maxPr;
    }
};