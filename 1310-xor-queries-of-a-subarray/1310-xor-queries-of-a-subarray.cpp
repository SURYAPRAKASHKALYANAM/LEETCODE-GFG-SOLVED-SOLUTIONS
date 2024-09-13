class Solution
{
    public:
        vector<int> xorQueries(vector<int> &arr, vector<vector< int>> &queries)
        {
            vector<int> pref(arr.size(), 0), ans;
            pref[0] = arr[0];
            for (int i = 1; i < arr.size(); i++) pref[i] = pref[i - 1] ^ arr[i];
            for (auto i: queries)   ans.emplace_back(pref[i[1]] ^ ((i[0] > 0) ? pref[i[0] - 1] : 0));
            return ans;
        }
};