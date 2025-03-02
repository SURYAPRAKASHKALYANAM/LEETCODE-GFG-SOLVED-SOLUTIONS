class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int len1 = nums1.size(), len2 = nums2.size();
        int pos1 = 0, pos2 = 0;
        while (pos1 < len1 && pos2 < len2) {
            if (nums1[pos1][0] == nums2[pos2][0]) {
                ans.push_back(
                    {nums1[pos1][0], nums1[pos1][1] + nums2[pos2][1]});
                pos1++, pos2++;
            } else if (nums1[pos1][0] < nums2[pos2][0]) {
                ans.push_back(nums1[pos1++]);
            } else
                ans.push_back(nums2[pos2++]);
        }
        while (pos1 < len1)
            ans.push_back(nums1[pos1++]);
        while (pos2 < len2)
            ans.push_back(nums2[pos2++]);
        return ans;
    }
};