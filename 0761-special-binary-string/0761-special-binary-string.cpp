class Solution {
public:
    string makeLargestSpecial(string s) {
        int balance = 0, start = 0;
        vector<string> blocks;
        for (int i = 0; i < s.size(); i++) {
            balance += (s[i] == '1' ? 1 : -1);
            if (balance == 0) {
                // string inner = s.substr(start + 1, i - start - 1);
                string optimized =
                    "1" +
                    makeLargestSpecial(s.substr(start + 1, i - start - 1)) +
                    "0";
                blocks.push_back(optimized);
                start = i + 1;
            }
        }
        sort(blocks.begin(), blocks.end(), greater<string>());
        return accumulate(blocks.begin(), blocks.end(), string(""));
    }
};