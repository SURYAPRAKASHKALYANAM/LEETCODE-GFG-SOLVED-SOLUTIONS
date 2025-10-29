class Solution {
public:
    bool check(string& s, string& sd, int& wLen) {
        int cnt = 0;
        for (int i = 0; i < wLen; i++) {
            if (s[i] != sd[i])
                cnt++;
            if (cnt > 2)
                return false;
        }
        return true;
    }
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> ans;
        int len = queries.size();
        int wLen = queries[0].size();
        for (string& s : queries) {
            for (string& sd : dictionary) {
                if (check(s, sd, wLen)) {
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};