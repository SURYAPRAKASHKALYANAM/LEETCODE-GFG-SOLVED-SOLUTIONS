class Solution {
public:
    int minimumDeletions(string s) {
        int len = s.size();
        // vector<int> deleteAt(len+1,0);
        int bBefore = 0, delPrev = 0, delCurr;
        for (int i = 0; i < len; i++) {
            if (s[i] == 'a') {
                delCurr = min(delPrev + 1, bBefore);
            } else {
                delCurr = delPrev;
                bBefore++;
            }
            delPrev = delCurr;
        }
        return delCurr;
    }
};