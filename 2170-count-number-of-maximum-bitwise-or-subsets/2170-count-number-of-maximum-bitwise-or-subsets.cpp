class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = accumulate(begin(nums), end(nums), 0, bit_or<>());
        unordered_map<int, int> seen;
        int orVal = 0, cnt = 1;
        for (int i : nums) {
            orVal |= i;
            seen[orVal]++;
            if (orVal == maxOr)
                cnt += seen[orVal];
        }
        return cnt;
    }
};