class Solution
{
public:
    struct ele
    {
        int x, y;
    };

    bool isDelim(ele z)
    {
        return (z.x == -1 && z.y == -1);
    }

    bool isSafe(int x, int y, int m, int n)
    {
        return (x >= 0 && y >= 0 && x < m && y < n);
    }

    bool allRotten(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    return false;
                }
            }
        }
        return true;
    }

    int orangesRotting(vector<vector<int>> &grid)
    {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<ele> q;
        ele temp;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    temp.x = i;
                    temp.y = j;
                    q.push(temp);
                }
            }
        }
        temp.x = -1;
        temp.y = -1;
        q.push(temp);
        while (!q.empty())
        {
            bool flag = false;

            while (!isDelim(q.front()))
            {
                temp = q.front();
                if (isSafe(temp.x + 1, temp.y, m, n) && grid[temp.x + 1][temp.y] == 1)
                {
                    if (!flag)
                    {
                        flag = true;
                        ans++;
                    }
                    temp.x++;
                    q.push(temp);
                    temp.x--;
                    grid[temp.x + 1][temp.y] = 2;
                }
                if (isSafe(temp.x - 1, temp.y, m, n) && grid[temp.x - 1][temp.y] == 1)
                {
                    if (!flag)
                    {
                        flag = true;
                        ans++;
                    }
                    temp.x--;
                    q.push(temp);
                    temp.x++;
                    grid[temp.x - 1][temp.y] = 2;
                }
                if (isSafe(temp.x, temp.y + 1, m, n) && grid[temp.x][temp.y + 1] == 1)
                {
                    if (!flag)
                    {
                        flag = true;
                        ans++;
                    }
                    temp.y++;
                    q.push(temp);
                    temp.y--;
                    grid[temp.x][temp.y + 1] = 2;
                }
                if (isSafe(temp.x, temp.y - 1, m, n) && grid[temp.x][temp.y - 1] == 1)
                {
                    if (!flag)
                    {
                        flag = true;
                        ans++;
                    }
                    temp.y--;
                    q.push(temp);
                    temp.y++;
                    grid[temp.x][temp.y - 1] = 2;
                }
                q.pop();
            }
            q.pop();
            if (!q.empty())
            {
                temp.x = -1;
                temp.y = -1;
                q.push(temp);
            }
        }
        if (allRotten(grid))
        {
            return ans;
        }
        else
        {
            return -1;
        }
    }
};