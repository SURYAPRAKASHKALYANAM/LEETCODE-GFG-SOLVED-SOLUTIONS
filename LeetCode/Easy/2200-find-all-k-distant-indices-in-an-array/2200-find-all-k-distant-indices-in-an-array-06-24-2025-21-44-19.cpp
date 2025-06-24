class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int len = nums.size();
        vector<int> keyspos(len, 0);
        for (int i = 0; i < len; i++) {
            if (nums[i] == key) {
                keyspos[max(0, i - k)] += 1;
                if ((i + k + 1) <= (len - 1))
                    keyspos[i + k + 1] -= 1;
            }
        }
        vector<int> ans;
        if (keyspos[0])
            ans.emplace_back(0);
        for (int i = 1; i < len; i++) {
            keyspos[i] += keyspos[i - 1];
            if (keyspos[i] > 0)
                ans.emplace_back(i);
        }
        return ans;
    }
};