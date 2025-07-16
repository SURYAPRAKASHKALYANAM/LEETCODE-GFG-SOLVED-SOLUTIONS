class Solution {
public:
    int merge(int start, int end, vector<int>& nums) {
        int cnt = 0;
        if (start < end) {
            int mid = (start + end) / 2;
            cnt += merge(start, mid, nums);
            cnt += merge(mid + 1, end, nums);
            cnt += countPairs(start, mid, end, nums);
            mergeSort(start, mid, end, nums);
        }
        return cnt;
    }

    int countPairs(int start, int mid, int end, vector<int>& nums) {
        int cnt = 0, right = mid + 1;
        for (int i = start; i <= mid; i++) {
            while (right <= end && ((long long)nums[i] > (long long)(2LL * nums[right])))
                right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    void mergeSort(int start, int mid, int end, vector<int>& nums) {
        int left = start, right = mid + 1;
        vector<int> temp;
        while (left <= mid && right <= end) {
            if (nums[left] <= nums[right]) {
                temp.emplace_back(nums[left++]);
            } else {
                temp.emplace_back(nums[right++]);
            }
        }
        while (left <= mid) {
            temp.emplace_back(nums[left++]);
        }
        while (right <= end) {
            temp.emplace_back(nums[right++]);
        }
        for (int i = start; i <= end; i++) {
            nums[i] = temp[i - start];
        }
    }

    int reversePairs(vector<int>& nums) {
        return merge(0, nums.size() - 1, nums);
    }
};