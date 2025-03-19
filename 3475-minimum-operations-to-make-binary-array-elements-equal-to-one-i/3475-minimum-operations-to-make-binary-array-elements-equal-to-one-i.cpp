class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        int start, end = 0, n = nums.size();
        while (end < n) {
            if (nums[end])
                end++;
            else {
                start = end;
                int next = end + 2;
                if (next >= n)
                    return -1;
                for (int i = start; i <= next; i++)
                    nums[i] = !nums[i];
                end++;
                cnt++;
            }
        }
        return cnt;
    }
};