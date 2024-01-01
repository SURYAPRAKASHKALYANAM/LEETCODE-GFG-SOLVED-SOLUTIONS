class Solution
{
    public:
        int findContentChildren(vector<int> &g, vector<int> &s)
        {
            sort(g.begin(), g.end());
            sort(s.begin(), s.end());
            int i = 0, j = 0;
            while (1)
            {
                if(j>=s.size() || i>=g.size()) break; 
                if (s[j] >= g[i])
                {
                    i++;
                    j++;
                }
                else j++;
            }
            return i;
        }
};