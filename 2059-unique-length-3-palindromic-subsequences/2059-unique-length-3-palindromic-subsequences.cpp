class Solution
{
    public:
        int countPalindromicSubsequence(string s)
        {
            map<char, int> right, left;
            for (auto i: s)
                right[i]++;
            int cnt = 0;
            unordered_map<string, int> m;
            for (int i = 0; i < s.size() - 1; i++)
            {
                right[s[i]]--;
                for (char j = 'a'; j <= 'z'; j++)
                {
                    string st = "";
                    st += j, st += s[i], st += j;
                    if (left[j] && right[j] && !m[st]) m[st] = ++cnt;
                }
                left[s[i]]++;
            }
            return cnt;
        }
};