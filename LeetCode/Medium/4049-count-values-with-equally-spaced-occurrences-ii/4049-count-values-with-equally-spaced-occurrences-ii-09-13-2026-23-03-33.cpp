class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> positions, distance, counts;
        for (int i = 0; i < nums.size(); i++) {
            if (positions.find(nums[i]) != positions.end()) {
                int gap = i - positions[nums[i]];
                if (distance[nums[i]] == 0) {
                    distance[nums[i]] = gap;
                } else if (gap != distance[nums[i]]) {
                    distance[nums[i]] = -1;
                }
            } else {
                distance[nums[i]] = 0;
            }
            positions[nums[i]] = i;
            counts[nums[i]]++;
        }
        int spl = 0;
        for (auto [key, cnt] : counts) {
            if (cnt >= 3 && distance[key] != -1)
                spl++;
        }
        return spl;
    }
};