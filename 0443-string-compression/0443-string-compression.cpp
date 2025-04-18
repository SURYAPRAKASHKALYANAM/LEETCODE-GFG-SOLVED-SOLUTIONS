class Solution {
public:
    int compress(vector<char>& chars) {
        int cnt = 1, len = chars.size(), i = 0, j = 0, start = 0;
        while (i < len) {
            cnt = 1;
            while (i + 1 < len && chars[i] == chars[i + 1])
                cnt++, i += 1;
            if (cnt > 1) {
                chars[start] = chars[i - cnt + 1];
                start += 1;
                string ns = to_string(cnt);
                for (char i : ns) {
                    chars[start++] = i;
                }
            } else {
                chars[start] = chars[i];
                start += 1;
            }
            i++;
        }
        if (cnt == 1 && start < len) {
            chars[start - 1] = chars[len - 1];
        }
        return start;
    }
};