class Solution
{
    public:
        string maximumOddBinaryNumber(string s)
        {
            unordered_map<char, int> m;
            for (auto i: s) m[i]++;
            string ans = "";
            for (int i = 0; i<m['1']-1; i++) ans += "1";
            for (int i = 0; i<m['0']; i++) ans += "0";
            ans += "1";
            return ans;
        }
};