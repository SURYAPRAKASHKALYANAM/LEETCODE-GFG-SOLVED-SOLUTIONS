class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0, num = 0, len;
        for (int i = low; i <= high; i++) {
            string s = to_string(i);
            num = 0, len = s.size();
            if (!(len & 1)) {
                int mid = len / 2;
                for (int i = 0; i < mid; i++) {
                    num += (s[i] - '0');
                }
                for (int i = mid; i < len; i++) {
                    num -= (s[i] - '0');
                }
                cnt += (num == 0);
            } else {
                i = pow(10, len);
            }
        }
        return cnt;
    }
};