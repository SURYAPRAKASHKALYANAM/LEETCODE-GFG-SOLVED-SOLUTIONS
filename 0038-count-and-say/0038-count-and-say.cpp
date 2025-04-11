class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string rle = countAndSay(n - 1), ans = "";
        int pos = 0;
        while (pos < rle.size()) {
            int cnt = 1;
            while (pos + 1 < rle.size() && rle[pos + 1] == rle[pos]) {
                cnt++;
                pos++;
            }
            ans += to_string(cnt) + rle[pos++];
        }
        return ans;
    }
};