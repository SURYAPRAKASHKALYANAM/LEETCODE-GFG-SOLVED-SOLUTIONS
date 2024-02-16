class Solution
{
    public:
        int findLeastNumOfUniqueInts(vector<int> &arr, int k)
        {
            priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> q;
            unordered_map<int, int> m;
            for (auto i: arr) m[i]++;
            for (auto i: m)
            {
                q.push({ i.second,i.first });
            }
            int left = 0;
            while (k)
            {
                auto it = q.top();
                int cnt = it.first;
                if(k<cnt) break;
                if (k >= cnt)
                {
                    k -= cnt;
                    q.pop();
                }
            }
            while (!q.empty())
            {
                q.pop();
                left++;
            }
            return left;
        }
};