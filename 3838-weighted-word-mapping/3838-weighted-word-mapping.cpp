class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for (string s : words) {
            int wt = 0;
            for (char ch : s) {
                wt += weights[ch - 'a'];
            }
            wt = wt % 26;
            ans += ('a' + (25 - wt));
        }
        return ans;
    }
};