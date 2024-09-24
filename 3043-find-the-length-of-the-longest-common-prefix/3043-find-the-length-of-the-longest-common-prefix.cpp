class Solution
{
    public:
        int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
        {
            int max_len = 0;
            unordered_map<int, int> m;
            for (auto i: arr1)
            {
                while (i)
                {
                    m[i] = i;
                    i /= 10;
                }
            }
            for (auto i: arr2)
            {
                while (i)
                {
                    if (m[i])
                    {
                        max_len = max(m[i], max_len);
                        break;
                    }
                    i /= 10;
                }
            }
            return max_len == 0 ? 0 : to_string(max_len).size();
        }
};