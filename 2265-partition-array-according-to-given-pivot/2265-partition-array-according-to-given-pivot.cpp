class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int less = 0, equal = 0, n = nums.size();
        vector<int> ans(n);
        for (auto i : nums)
            less += (i < pivot), equal += (i == pivot);
        int start = 0, right = less + equal;
        for (int i : nums) {
            if (i < pivot)
                ans[start++] = i;
            else if (i > pivot)
                ans[right++] = i;
            else
                ans[less++] = i;
        }
        return ans;
    }
};