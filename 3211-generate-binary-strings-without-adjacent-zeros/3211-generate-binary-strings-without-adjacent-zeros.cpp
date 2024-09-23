class Solution
{
    public:
        void add(string s, bool zero, vector<string> &ans, int &n)
        {
            if (s.size() == n)
            {
                ans.emplace_back(s);
                return;
            }
            if (!zero)
            {
                s += '0';
                zero = !zero;
                add(s, zero, ans, n);
                s.pop_back();
            }
            s += '1';
            zero = !zero;
            add(s, zero, ans, n);
        }
    vector<string> validStrings(int n)
    {
        string s = "";
        vector<string> ans;
        add(s, false, ans, n);
        return ans;
    }
};