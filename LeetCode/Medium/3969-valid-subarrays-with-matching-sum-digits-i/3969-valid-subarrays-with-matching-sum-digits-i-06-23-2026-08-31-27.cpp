class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int len = nums.size();
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            long long sum = 0;
            for (int j = i; j < len; j++) {
                sum += nums[j];
                int noOfd = log10(sum);
                if ((sum % 10 == x) && ((int)(sum / pow(10, noOfd)) == x))
                    cnt++;
            }
        }
        return cnt;
    }
};