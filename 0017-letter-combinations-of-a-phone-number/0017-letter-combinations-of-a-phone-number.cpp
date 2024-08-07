class Solution
{
    public:
        void dfs(string digits, vector<string> &ans, string curr, int pos, unordered_map<int, string> m)
        {
            if (pos == digits.size() && curr != "")
            {
                ans.emplace_back(curr);
                return;
            }
            for (auto i = 0; i < m[digits[pos] - '0'].size(); i++)
            {
                curr += m[digits[pos] - '0'][i];
                dfs(digits, ans, curr, pos + 1, m);
                curr.pop_back();
            }
        }
    vector<string> letterCombinations(string digits)
    {
        unordered_map<int, string> m;
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        vector<string> ans;
        string curr = "";
        int pos = 0;
        dfs(digits, ans, curr, pos, m);
        return ans;
    }
};