class Solution {
public:
    long long helper(long long maxi, long long zeros1, long long mini,
                     long long zeros2) {
        // cout << maxi << " " << zeros1 << " " << mini << " " << zeros2;
        maxi += zeros1;
        if (!zeros2)
            return maxi == mini ? maxi : -1;
        return ((maxi - mini) >= zeros2) ? maxi : -1;
    }
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long zeros1 = count(nums1.begin(), nums1.end(), 0);
        long long zeros2 = count(nums2.begin(), nums2.end(), 0);
        long long sum1 = accumulate(nums1.begin(), nums1.end(), 0L);
        long long sum2 = accumulate(nums2.begin(), nums2.end(), 0L);
        if (sum2 + zeros2 > sum1 + zeros1) {
            return helper(sum2, zeros2, sum1, zeros1);
        }
        return helper(sum1, zeros1, sum2, zeros2);
    }
};