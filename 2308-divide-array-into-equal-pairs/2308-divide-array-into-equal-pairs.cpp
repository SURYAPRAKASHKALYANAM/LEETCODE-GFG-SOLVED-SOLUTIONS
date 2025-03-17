class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto i : nums)
            m[i]++;
        for (auto pair : m) {
            if (pair.second & 1)
                return false;
        }
        return true;
    }
};