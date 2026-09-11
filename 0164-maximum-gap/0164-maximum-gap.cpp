class Solution {
public:
    int maximumGap(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        int prev = -1, max_len = 0;
        for (auto i : st) {
            if (prev != -1)
                max_len = max(max_len, i - prev);
            prev = i;
        }
        return max_len;
    }
};