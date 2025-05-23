class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        for (int i : nums)
            cnt += min(3 - i % 3, i % 3);
        return cnt;
    }
};