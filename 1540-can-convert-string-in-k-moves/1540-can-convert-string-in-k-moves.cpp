class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int n = s.size();
        if (n != t.size())
            return false;
        unordered_map<int,int> diffMoved,moved;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                int step = 0;
                if (s[i] < t[i]) {
                    step = (t[i] - s[i]);
                } else {
                    step = ('z' - s[i]) + (t[i] - 'a' + 1);
                }
                // cout << i << " " << step << " ";
                int started = step;
                if(diffMoved[started]) step=diffMoved[started]; 
                while (step <= k && moved[step]) {
                    step += 26;
                }
                if (step <= k) {
                    moved[step] = 1;
                } else
                    return false;
                diffMoved[started] = step;
            }
        }
        return true;
    }
};