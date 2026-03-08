class Solution {
public:
    unordered_map<string, bool> have;
    bool helper(string& curr, int len) {
        if (curr.size() == len) {
            return !have[curr];
        }
        for (char c = '0'; c <= '1'; c++) {
            curr += c;
            if (helper(curr, len))
                return true;
            curr.pop_back();
        }
        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        for (auto i : nums)
            have[i] = true;
        string ans = "";
        helper(ans, n);
        return ans;
    }
};