class AllOne
{
    public:
    unordered_map<string, int> m;
    set<pair<int, string>> order;
    AllOne() {}

    void inc(string key)
    {
        int n = m[key];
        m[key]++;
        if (n) order.erase({ n,
            key });
        order.insert({ n + 1,
            key });
    }

    void dec(string key)
    {
        int n = m[key];
        order.erase({ n,
            key });
        m[key]--;
        if (n - 1 == 0) order.erase({ n - 1,
            key });
        else order.insert({ n - 1,
            key });
    }

    string getMaxKey()
    {
        return order.empty() ? "" : order.rbegin()->second;
    }

    string getMinKey()
    {
        return order.empty() ? "" : order.begin()->second;
    }
};

/**
 *Your AllOne object will be instantiated and called as such:
 *AllOne* obj = new AllOne();
 *obj->inc(key);
 *obj->dec(key);
 *string param_3 = obj->getMaxKey();
 *string param_4 = obj->getMinKey();
 */