class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        // int start, end, mid;
        int max_dis = 0;
        // optimal
        int p1 = 0, p2 = 0;
        while (p1 < m && p2 < n) {
            if (nums1[p1] <= nums2[p2]) {
                max_dis = max(max_dis, p2 - p1);
                p2++;
            } else
                p1++;
        }
        // for (int i = 0; i < n; i++) {
        //     if (i + 1 < n && nums2[i] == nums2[i + 1])
        //         continue;
        //     start = 0, end = min(i, m - 1);
        //     while (start <= end) {
        //         mid = start + (end - start) / 2;
        //         if (nums1[mid] <= nums2[i])
        //             end = mid - 1;
        //         else
        //             start = mid + 1;
        //     }
        //     if (start <= min(i, m - 1))
        //         max_dis = max(max_dis, (i - start));
        // }
        return max_dis;
    }
};