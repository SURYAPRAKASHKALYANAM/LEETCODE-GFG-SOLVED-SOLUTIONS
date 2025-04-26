class Solution {
public:
    void func(vector<int>& nums, int& cnt, int goal) {
        int start = 0, end = 0, curr = 0, postend = 0;
        int n = nums.size();
        while (end < n) {
            while (curr < goal && end < n) {
                if (nums[end])
                    curr++;
                end++;
            }
            postend = end;
            while (postend < n && !nums[postend]) {
                postend++;
            }
            while (curr == goal && start <= end) {
                    cnt += (1 + (postend - end));
                if (nums[start])
                    curr--;
                start++;
            }
        }
        return;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt = 0;
        if (goal == 0) {
            int n = nums.size();
            int start = 0, end = 0;
            while (end < n) {
                if (nums[end])
                    end++;
                start = end;
                while (end < n && !nums[end]) {
                    end++;
                }
                int gap = end - start;
                cnt += gap * (gap + 1) / 2;
                start = end++;
            }

        } else
            func(nums, cnt, goal);
        return cnt;
    }
};