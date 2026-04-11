class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> idxs;
        int min_dis = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            idxs[nums[i]].push_back(i);

            if (idxs[nums[i]].size() >= 3) {
                int l = idxs[nums[i]].size();
                min_dis =
                    min(min_dis,
                        abs(idxs[nums[i]][l - 2] - idxs[nums[i]][l - 3]) +
                            abs(idxs[nums[i]][l - 2] - idxs[nums[i]][l - 1]) +
                            abs(idxs[nums[i]][l - 1] - idxs[nums[i]][l - 3]));
            }
        }

        return min_dis != INT_MAX ? min_dis : -1;
    }
};