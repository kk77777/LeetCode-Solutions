class Solution
{
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
    {
        vector<int> result(3, INT_MIN);
        for (int i = 0; i < triplets.size(); i++)
        {
            if (result[0] == target[0] && result[1] == target[1] && result[2] == target[2])
                return true;
            if (triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2])
            {
                continue;
            }
            result[0] = max(triplets[i][0], result[0]);
            result[1] = max(triplets[i][1], result[1]);
            result[2] = max(triplets[i][2], result[2]);
        }

        if (result[0] == target[0] && result[1] == target[1] && result[2] == target[2])
            return true;
        return false;
    }
};