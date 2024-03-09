class Solution
{
    public:
        int getCommon(vector<int> &nums1, vector<int> &nums2)
        {
            int p1 = 0, p2 = 0;
            while (p1 < nums1.size() && p2 < nums2.size())
            {
                if (nums1[p1] == nums2[p2]) return nums1[p1];
                if (nums1[p1] < nums2[p2])
                    for (; p1 + 1 < nums1.size() && nums1[p1] == nums1[p1 + 1]; p1++);
                else
                    for (; p2 + 1 < nums2.size() && nums2[p2] == nums2[p2 + 1]; p2++);
                if (p1 < nums1.size() && p2 < nums2.size() && nums1[p1] < nums2[p2]) p1++;
                else p2++;
            }
            return -1;
        }
};