class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int len = nums.size(), cnt = 0;
        vector<int> ans;
        map<int,int> pos;
        for (int i = 0; i < len; i++) {
            if (nums[i] == key) {
                cnt = k+1;
            }
            if (cnt > 0) {
                pos[i]=1;
                cnt--;
            }
        }
        cnt = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (nums[i] == key) {
                cnt = k + 1;
            }
            if (cnt > 0) {
                pos[i]=1;
                cnt--;
            }
        }
        for(auto i:pos) ans.emplace_back(i.first);
        return ans;
    }
};