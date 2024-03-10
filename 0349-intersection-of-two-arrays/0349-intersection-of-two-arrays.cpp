class Solution
{
    public:
        vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
        {
            unordered_map<int, int> m;
            vector<int> ans;
            for (auto i: nums1) m[i] = 1;
            for (auto i: nums2)
            {
                if (m[i])
                {
                    ans.emplace_back(i);
                    m[i] = 0;
                }
            }
            return ans;
        }
};