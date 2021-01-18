class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0)
            return false;
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, h = (n * m) - 1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (matrix[mid / m][mid % m] == target)
                return true;
            else if (matrix[mid / m][mid % m] > target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
};