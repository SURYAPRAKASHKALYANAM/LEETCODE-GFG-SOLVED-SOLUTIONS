class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        set<int> st(special.begin(), special.end());
        int max_len = 0, prev = -1;
        max_len = max(max_len, *st.begin() - bottom);
        for (auto i : st) {
            if (prev != -1)
                max_len = max(max_len, i - prev - 1);
            prev = i;
        }
        max_len = max(max_len, top - *st.rbegin());
        return max_len;
    }
};