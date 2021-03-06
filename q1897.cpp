class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        int n = words.size();
        unordered_map<char, int> mp;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].length(); j++)
            {
                mp[words[i][j]]++;
            }
        }
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second % n != 0)
            {
                return false;
            }
        }
        return true;
    }
};