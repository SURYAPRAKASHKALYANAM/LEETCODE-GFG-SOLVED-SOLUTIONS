class Solution
{
    public:
        vector<int> frequencySort(vector<int> &nums)
        {
            map<int, int> m;
            for (auto i: nums) m[i]++;
            sort(nums.begin(), nums.end(), [& ](int n1, int n2){
                return m[n1] == m[n2] ? n1 > n2 : m[n1] < m[n2];
            });
            return nums;
        }
};