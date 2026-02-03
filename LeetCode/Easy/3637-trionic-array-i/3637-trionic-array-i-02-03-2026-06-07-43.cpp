class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int len = nums.size(), start = 0;
        int p = -1, q = -1, r = -1;
        while (start < len) {
            p = start;
            if (start + 1 < len && nums[start] >= nums[start + 1]) {
                break;
            }
            start++;
        }
        while (start < len) {
            q = start;
            if (start + 1 < len && nums[start] <= nums[start + 1]) {
                break;
            }
            start++;
        }
        while (start < len) {
            r = start;
            if (start + 1 < len && nums[start] >= nums[start + 1]) {
                break;
            }
            start++;
        }
        // cout<<p<<" "<<q<<" "<<r<<endl<<start;
        if (p == -1 || q == -1 || r == -1 || p<1 || (q - p) < 1 || (r - q) < 1)
            return false;
        if(start<len) return false;
        return p < q && q < r;
    }
};