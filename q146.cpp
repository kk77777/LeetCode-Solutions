class LRUCache
{
public:
    int cp, size = 0;
    unordered_map<int, int> mp;
    list<int> l;
    LRUCache(int capacity)
    {
        cp = capacity;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            l.remove(key);
            l.push_back(key);
            return mp[key];
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            l.remove(key);
            l.push_back(key);
            mp[key] = value;
        }
        else
        {
            if (size == cp)
            {
                mp.erase(l.front());
                l.erase(l.begin());
                mp.insert({key, value});
                l.push_back(key);
            }
            else
            {
                l.push_back(key);
                mp.insert({key, value});
                size++;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */