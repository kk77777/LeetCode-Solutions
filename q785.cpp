class Solution
{
public:
    bool bfs(int x, vector<vector<int>> graph, vector<int> &color)
    {
        queue<int> q;
        color[x] = 1;
        q.push(x);
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            for (auto it : graph[temp])
            {
                if (color[it] == -1)
                {
                    color[it] = 1 - color[temp];
                    q.push(it);
                }
                else if (color[it] == color[temp])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n + 1, -1);
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (!bfs(i, graph, color))
                {
                    return false;
                }
            }
        }
        return true;
    }
};