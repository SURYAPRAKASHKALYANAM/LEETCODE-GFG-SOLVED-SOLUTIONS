class Solution
{
    public:
    set<vector < int>> s;
    void find(int &ans, vector<int> &nums, vector<int> temp, int max_or, int pos)
    {
        sort(temp.begin(), temp.end());
        if (s.find(temp) == s.end())
        {
            s.insert(temp);
            int curr_or = 0;
            for (auto i: temp) curr_or |= nums[i];
            if (curr_or == max_or) ans++;
        }
        for (int i = pos; i < nums.size(); i++)
        {
            temp.push_back(i);
            find(ans, nums, temp, max_or, i + 1);
            temp.pop_back();
        }
    }
    int countMaxOrSubsets(vector<int> &nums)
    {
        int max_or = 0;
        for (auto i: nums) max_or |= i;
        int ans = 0, pos = 0;
        vector<int> temp;
        find(ans, nums, temp, max_or, pos);
        return ans;
    }
};