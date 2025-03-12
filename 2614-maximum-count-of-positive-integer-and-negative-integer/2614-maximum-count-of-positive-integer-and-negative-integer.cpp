class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // O(N)
        // int pos = 0, neg = 0;
        // for (auto i : nums) {
        //     (i > 0) ? pos++ : neg += (i < 0);
        // }
        // return max(pos, neg);
        //  O (log(N))
        int start = 0, end = nums.size() - 1, mid;
        int n = nums.size();
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] >= 0 && mid - 1 >= 0 && nums[mid - 1] <= 0)
                break;
            else if (nums[mid] >= 0)
                end = mid - 1;
            else
                start = mid + 1;
        }
        int lmid,rmid=lmid=mid;
        while(lmid>=0 && nums[lmid]>=0) lmid--;
        while(rmid<n && nums[rmid]<=0) rmid++;
        return max(lmid+1, n - rmid);
    }
};