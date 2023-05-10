class MapSum
{
    public:
    map<string, int> m;
    MapSum() {}

    void insert(string key, int val)
    {
        m[key] = val;
    }

    int sum(string prefix)
    {
        int c = 0;
        for (auto i: m)
        {
            if (i.first.substr(0, prefix.size()) == prefix) c += i.second;
        }
        return c;
    }
};

/**
 *Your MapSum object will be instantiated and called as such:
 *MapSum* obj = new MapSum();
 *obj->insert(key,val);
 *int param_2 = obj->sum(prefix);
 */