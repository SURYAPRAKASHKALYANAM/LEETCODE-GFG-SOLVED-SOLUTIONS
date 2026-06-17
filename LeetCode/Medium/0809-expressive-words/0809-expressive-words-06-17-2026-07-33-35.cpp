class Solution {
public:
    void findCnts(string& s, vector<pair<char, int>>& cnts) {
        int len = s.size();
        int l = 0, r = 0;
        while (r <= len) {
            while (r < len && s[r] == s[l])
                r++;
            cnts.push_back({s[l], r - l});
            l = r;
            r++;
        }
    }
    bool isStretchy(vector<pair<char, int>>& sCnts,
                    vector<pair<char, int>>& currCnts) {
        if (sCnts.size() != currCnts.size())
            return false;
        int p1 = 0;
        int len = sCnts.size();
        while (p1 < len) {
            if (sCnts[p1].first == currCnts[p1].first) {
                int c1 = sCnts[p1].second, c2 = currCnts[p1].second;
                if (c1 != c2 && (c1 < c2 || c1 < 3)) {
                    return false;
                }
            } else {
                return false;
            }
            p1++;
        }
        return true;
    }
    int expressiveWords(string s, vector<string>& words) {
        vector<pair<char, int>> sCnts;
        findCnts(s, sCnts);
        int res = 0;
        for (string& curr : words) {
            vector<pair<char, int>> currCnts;
            findCnts(curr, currCnts);
            res += isStretchy(sCnts, currCnts);
        }
        return res;
    }
};