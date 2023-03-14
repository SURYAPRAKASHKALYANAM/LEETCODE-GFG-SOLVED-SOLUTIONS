class Solution
{
    public:
        vector<int> rearrangeArray(vector<int> &nums)
        {
            bool flag = true;
            int start = 0;
            vector<int> ans, pos, neg;
            for (auto i: nums)
            {
                if (i > 0) pos.emplace_back(i);
                else neg.emplace_back(i);
            }
            while (start < nums.size() / 2)
            {
                if (flag)
                {
                    ans.emplace_back(pos[start]);
                }
                else
                {
                    ans.emplace_back(neg[start++]);
                }
                flag = !flag;
            }
            return ans;
        }
};