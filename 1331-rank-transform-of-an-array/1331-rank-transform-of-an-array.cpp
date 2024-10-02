class Solution
{
    public:
        vector<int> arrayRankTransform(vector<int> &arr)
        {
            vector<int> ans(arr.size());
            map<int, vector < int>> m;
            for (auto i = 0; i < arr.size(); i++) m[arr[i]].emplace_back(i + 1);
            int rank = 1;
            for (auto i: m)
            {

                for (auto ele: i.second) arr[ele - 1] = rank;
                rank++;
            }
            return arr;
        }
};