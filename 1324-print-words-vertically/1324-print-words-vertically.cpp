class Solution {
public:
    void trimRight(std::string& str) {
        auto end_pos = std::find_if_not(str.rbegin(), str.rend(), [](unsigned char c){
            return std::isspace(c);
        }).base();
        str.erase(end_pos, str.end());
    }
    vector<string> printVertically(string s) {
        vector<string> splits, ans;
        stringstream ss(s);
        string sub;
        int max_len = 0;
        while (ss >> sub) { // whitespaces
            splits.push_back(sub);
            max_len = max(max_len, (int)sub.size());
        }
        int idx = 0;
        for (int idx = 0; idx < max_len; idx++) {
            sub = "";
            for (string& temps : splits) {
                if (temps.size() > idx)
                    sub += temps[idx];
                else
                    sub += " ";
            }
            trimRight(sub);
            ans.emplace_back(sub);
        }
        return ans;
    }
};