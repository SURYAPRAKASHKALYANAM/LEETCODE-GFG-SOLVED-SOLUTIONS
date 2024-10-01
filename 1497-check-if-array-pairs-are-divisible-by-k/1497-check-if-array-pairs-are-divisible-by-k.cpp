class Solution
{
    public:
        bool canArrange(vector<int> &arr, int k)
        {
            unordered_map<int, int> m;
            for (auto i: arr) m[((i %k) + k) % k]++;
            if(m[0]%2==1) return false;
            for (int i = 1; i < k; i++)
            {
                if (m[i] == m[k - i]) continue;
                else
                {
                    cout<<i;
                    return false;
                }
            }
            return true;
        }
};