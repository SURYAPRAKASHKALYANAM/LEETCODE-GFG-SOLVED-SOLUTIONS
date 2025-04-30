class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (auto i : nums) {
            cnt += (((int)log10(i)) & 1);
        }
        return cnt;
    }
};