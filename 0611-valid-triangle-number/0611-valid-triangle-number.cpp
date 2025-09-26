class Solution {
public:
    bool check(int& l, int& r, int& mid, vector<int>& nums) {
        if ((nums[l] + nums[r]) <= nums[mid])
            return false;
        if ((nums[l] + nums[mid]) <= nums[r])
            return false;
        if ((nums[mid] + nums[r]) <= nums[l])
            return false;
        // cout << l << " " << r << " " << mid << endl;
        return true;
    }
    int triangleNumber(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        auto new_end = remove(nums.begin(), nums.end(), 0);
        nums.erase(new_end, nums.end());
        int cnt = 0;
        int len = nums.size();
        for (int l = 0; l < len; l++) {
            for (int r = l + 1; r < len - 1; r++) {
                int start = r + 1, end = len - 1, mid;
                int pos = -1;
                while (start <= end) {
                    mid = (start + end) / 2;
                    if (check(l, r, mid, nums)) {
                        pos = mid;
                        start = mid + 1;
                    } else
                        end = mid - 1;
                }
                if (pos != -1 && pos != r) {
                    cnt += (pos - r);
                }
            }
        }
        return cnt;
    }
};