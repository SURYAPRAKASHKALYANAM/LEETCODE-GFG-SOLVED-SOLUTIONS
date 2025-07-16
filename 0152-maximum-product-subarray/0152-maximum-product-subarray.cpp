class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = INT_MIN;
        int pref = 1, suff = 1;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (pref == 0)
                pref = 1;
            if (suff == 0)
                suff = 1;
            pref = pref * nums[i];
            suff = suff * nums[len - i - 1];
            max_product = max(max_product, max(pref, suff));
        }
        return max_product;
    }
};