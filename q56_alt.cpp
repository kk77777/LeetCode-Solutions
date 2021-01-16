class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int index = 0;
        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < intervals.size(); i++)
        {
            if ((intervals[i][0] <= intervals[index][1]))
            {
                intervals[index][1] = max(intervals[index][1], intervals[i][1]);
            }
            else
            {
                index++;
                intervals[index] = intervals[i];
            }
        }
        intervals.erase(intervals.begin() + index + 1, intervals.end());
        return intervals;
    }
};