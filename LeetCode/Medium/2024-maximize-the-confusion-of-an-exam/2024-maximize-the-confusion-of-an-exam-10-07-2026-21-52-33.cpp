class Solution {
public:
    bool possible(int& wind, vector<int>& pref, int& k, int& len) {
        for (int i = wind; i <= len; i++) {
            if (wind - (pref[i] - pref[i - wind]) <= k ||
                (pref[i] - pref[i - wind]) <= k)
                return true;
        }
        return false;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int len = answerKey.size();
        vector<int> pref(len + 1, 0);
        for (int i = 0; i < len; i++) {
            pref[i + 1] = (answerKey[i] == 'T' ? 1 : 0);
            if (i - 1 >= 0)
                pref[i + 1] += pref[i + 1 - 1];
        }
        int start = 1, end = len, mid;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (possible(mid, pref, k, len))
                start = mid + 1;
            else
                end = mid - 1;
        }
        return end;
    }
};