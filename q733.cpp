class Solution
{
public:
    void fill(vector<vector<int>> &v, int prev, int toFill, int r, int c, int n, int m)
    {
        if (r < 0 || r >= n || c < 0 || c >= m)
            return;
        if (v[r][c] != prev)
            return;
        v[r][c] = toFill;
        fill(v, prev, toFill, r - 1, c, n, m);
        fill(v, prev, toFill, r + 1, c, n, m);
        fill(v, prev, toFill, r, c - 1, n, m);
        fill(v, prev, toFill, r, c + 1, n, m);
        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int n = image.size();
        int m = image[0].size();
        int prev = image[sr][sc];
        if (prev == newColor)
            return image;
        fill(image, prev, newColor, sr, sc, n, m);
        return image;
    }
};