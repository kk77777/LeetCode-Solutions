/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    void dfs(Node *x, unordered_map<Node *, Node *> &mp)
    {
        Node *xCopy = new Node(x->val);
        mp[x] = xCopy;
        for (auto i : x->neighbors)
        {
            if (mp.find(i) == mp.end())
            {
                dfs(i, mp);
            }
        }
    }
    void addEdges(unordered_map<Node *, Node *> &mp)
    {
        for (auto i : mp)
        {
            for (auto j : i.first->neighbors)
            {
                i.second->neighbors.push_back(mp[j]);
            }
        }
    }

    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;
        unordered_map<Node *, Node *> mp;
        dfs(node, mp);
        addEdges(mp);
        return mp[node];
    }
};