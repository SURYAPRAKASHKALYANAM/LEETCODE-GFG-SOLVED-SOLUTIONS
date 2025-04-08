class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> seen(101, 0);
        int n = nums.size(), i = n - 1;
        for (; i >= 0; i--) {
            if (seen[nums[i]])
                break;
            seen[nums[i]] = 1;
        }
        i += 1;
        return i / 3 + ((i % 3) ? 1 : 0);
    }
};