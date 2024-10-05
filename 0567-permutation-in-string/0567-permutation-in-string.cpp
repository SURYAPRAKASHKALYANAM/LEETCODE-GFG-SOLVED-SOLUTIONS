class Solution
{
    public:
        bool checkInclusion(string s1, string s2)
        {
            int len = s1.size();
            vector<int> m1(26, 0), m2(26, 0);
            for (int i = 0; i < s1.size(); i++) m1[s1[i] - 'a']++;
            int start = 0, end = 0;
            while (end < s2.size())
            {
                m2[s2[end] - 'a']++;
                if (end - start + 1 == len)
                {
                    if (m1 == m2) return true;
                }
                if (end - start + 1 < len) end++;
                else
                {
                    m2[s2[start] - 'a']--;
                    start++;
                    end++;
                }
            }
            return false;
        }
};