class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int len = nums.size();
        unordered_map<int, int> cnts;
        int sum = 0;
        int start = 0, prevStart = 0, min_len = INT_MAX;
        while (start < len) {
            if (sum < k) {
                if (cnts[nums[start]] == 0)
                    sum += nums[start];
                cnts[nums[start]]++;
                start++;
            } else {
                min_len = min(min_len, start - prevStart);
                if (cnts[nums[prevStart]] == 1)
                    sum -= nums[prevStart];
                cnts[nums[prevStart]]--;
                prevStart++;
            }
        }
        while (sum >= k) {
            min_len = min(min_len, start - prevStart);
            if (cnts[nums[prevStart]] == 1)
                sum -= nums[prevStart];
            cnts[nums[prevStart]]--;
            prevStart++;
        }
        return min_len == INT_MAX ? -1 : min_len;
    }
};