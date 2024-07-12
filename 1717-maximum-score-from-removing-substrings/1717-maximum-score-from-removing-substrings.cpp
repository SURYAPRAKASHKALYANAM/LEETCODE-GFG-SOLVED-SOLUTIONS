class Solution
{
    public:
        vector<char> helper(vector<char> st, int &ans, int add, string a_x)
        {
            vector<char> res;
            for (auto i: st)
            {
                if (i == a_x[1] && !res.empty() && res.back() == a_x[0])
                {
                    res.pop_back();
                    ans += add;
                }
                else res.push_back(i);
            }
            return res;
        }
    int maximumGain(string s, int x, int y)
    {
        int ans = 0;
        string a_x = "ab", b_y = "ba";
        if (y > x) swap(a_x, b_y), swap(x, y);
        vector<char> st(s.begin(), s.end());
        helper(helper(st, ans, x, a_x), ans, y, b_y);
        return ans;
    }
};