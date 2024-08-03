class Solution
{
    public:
        bool canBeEqual(vector<int> &target, vector<int> &arr)
        {
            unordered_map<int, int> counts;
            for (auto i: target) counts[i]++;
            for (auto i: arr) counts[i]--;
            for (auto i: target)
            {
                if (counts[i]!=0) return false;
            }
            return true;
        }
};