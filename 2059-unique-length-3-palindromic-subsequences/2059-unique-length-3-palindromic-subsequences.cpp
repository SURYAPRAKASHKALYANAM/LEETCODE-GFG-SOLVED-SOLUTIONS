class Solution
{
    public:
        int countPalindromicSubsequence(string s)
        {
           	// map<char, int> right, left;
           	// for (auto i: s)
           	//     right[i]++;
           	// int cnt = 0;
           	// unordered_map<string, int> m;
           	// for (int i = 0; i < s.size() - 1; i++)
           	// {
           	//     right[s[i]]--;
           	//     for (char j = 'a'; j <= 'z'; j++)
           	//     {
           	//         string st = "";
           	//         st += j, st += s[i], st += j;
           	//         if (left[j] && right[j] && !m[st]) m[st] = ++cnt;
           	//     }
           	//     left[s[i]]++;
           	// }
           	// return cnt;

            bitset<26> exist;
            int ans = 0;
            for (int i = 0; i < 26; i++)
            {
                int l = s.find('a' + i);
                if (l != string::npos)
                {
                    int r = s.find_last_of('a' + i);
                    if (r - l < 2) continue;
                    for (int k = l + 1; k < r; k++)
                    {
                        exist.set(s[k] - 'a');
                        if (exist.count() == 26) break;
                    }
                    ans += exist.count();
                    exist.reset();
                }
            }
            return ans;
        }
};