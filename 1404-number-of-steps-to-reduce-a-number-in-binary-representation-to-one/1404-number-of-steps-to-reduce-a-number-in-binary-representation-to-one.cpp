class Solution {
public:
    bool addOne(string& s, int pos) {
        while (pos >= 0 && s[pos] == '1') {
            s[pos] = '0';
            pos--;
        }
        if (pos < 0) {
            s = "1" + s;
            return true;
        }
        s[pos] = '1';
        return false;
    }
    int numSteps(string s) {
        int len = s.size(), cnt = 0;
        for (int i = len - 1; i > 0; i--) {
            if (s[i] == '1') {
                cnt += 2;
                bool increased = addOne(s, i);
                if (increased)
                    i++;
            } else {
                cnt += 1;
            }
        }
        return cnt;
    }
};