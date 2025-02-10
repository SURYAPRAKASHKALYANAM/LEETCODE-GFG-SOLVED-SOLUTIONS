class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long cnt = 0;
        unordered_map<int, int> prev;
        prev[nums[0]] = 1;
        for (int j = 1; j < nums.size(); j++) {
            cnt += (j - prev[nums[j] - j]);
            prev[nums[j] - j]++;
        }
        return cnt;
    }
};