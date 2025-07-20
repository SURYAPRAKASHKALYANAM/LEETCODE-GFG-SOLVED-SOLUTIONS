class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int len = m + n;
        int gap = (len / 2) + (len % 2);
        while (gap > 0) {
            int left = 0, right = gap;
            while (right < len) {
                if (left < m && right < m) {
                    if (nums1[left] > nums1[right]) {
                        swap(nums1[left], nums1[right]);
                    }
                } else if (left < m && right >= m) {
                    if (nums1[left] > nums2[right - m]) {
                        swap(nums1[left], nums2[right - m]);
                    }
                } else {
                    if (nums2[left - m] > nums2[right - m]) {
                        swap(nums2[left - m], nums2[right - m]);
                    }
                }
                left++;
                right++;
            }
            if (gap == 1)
                break;
            gap = gap / 2 + (gap % 2);
        }
        for(auto i:nums1) cout<<i<<" ";
        int midI = len / 2;
        if (len & 1) {
            if (midI < m)
                return (double)nums1[midI];
            return (double)nums2[midI-m];
        }
        if (midI < m && (midI - 1) < m) {
            return ((double)nums1[midI] + (double)nums1[midI]) / (double)2;
        } else if (midI - 1 < m && midI >= m) {
            return ((double)nums1[midI - 1] + (double)nums2[midI - m]) /
                   (double)2;
        }
        return ((double)nums2[midI - 1 - m] + (double)nums2[midI - m]) /
               (double)2;
    }
};