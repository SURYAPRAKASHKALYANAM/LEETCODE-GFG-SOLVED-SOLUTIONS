class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size(), start = 0, end = 0, distinct = 0;
        unordered_map<int, int> seen;
        for (auto i : nums) {
            distinct += (seen[i] == 0);
            seen[i] = 1;
        }
        int curr = 0, cnt = 0;
        seen.clear();
        while (end <= n) {
            while (curr == distinct && start <= end) {
                cnt += (1 + (n - end));
                if (seen[nums[start]])
                    seen[nums[start]]--;
                if (seen[nums[start]] == 0)
                    curr--;
                start++;
            }
            if (end == n)
                break;
            while (curr < distinct && end < n) {
                if (!seen[nums[end]]) {
                    curr++;
                }
                seen[nums[end]]++;
                end++;
            }
        }
        return cnt;
    }
};