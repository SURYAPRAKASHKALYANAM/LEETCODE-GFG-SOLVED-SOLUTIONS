class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans, equal, smaller, greater;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > pivot) {
                greater.push_back(nums[i]);
            } else if (nums[i] < pivot)
                smaller.push_back(nums[i]);
            else
                equal.push_back(nums[i]);
        }
        for (auto i : smaller) {
            ans.push_back(i);
        }
        for (auto i : equal) {
            ans.push_back(i);
        }
        for (auto i : greater) {
            ans.push_back(i);
        }
        return ans;
    }
};