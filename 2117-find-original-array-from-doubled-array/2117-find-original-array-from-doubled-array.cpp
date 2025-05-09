class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        int n = changed.size();
        if (n & 1)
            return ans;
        sort(changed.begin(), changed.end());
        unordered_map<int, int> counts;
        for (int i : changed)
            counts[i]++;
        while (n > 0) {
            int changeEle = changed[n - 1], original = changeEle / 2;
            if (counts[changeEle] == 0) {
                n--;
                continue;
            }
            if ((changeEle & 1 || !counts[original]))
                return {};
            int cnt = counts[changeEle];
            if (changeEle == original) {
                cnt /= 2;
            }
            counts[original] -= cnt;
            counts[changeEle] = 0;
            while (cnt > 0) {
                cnt--;
                ans.emplace_back(original);
            }
            n--;
        }
        return ans;
    }
};