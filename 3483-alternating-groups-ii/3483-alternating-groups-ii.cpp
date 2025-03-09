class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        vector<int> prefixmatch(n + k);
        for (int i = 0; i < k - 1; i++)
            colors.emplace_back(colors[i]);
        n += k - 1;
        prefixmatch[0] = 1;
        for (int i = 1; i < n; i++) {
            if (colors[i] != colors[i - 1])
                prefixmatch[i] += prefixmatch[i - 1] + 1;
            else
                prefixmatch[i] = 1;
        }
        int cnt = 0;
        for (int i = k - 1; i < n; i++) {
            if (prefixmatch[i] - prefixmatch[i - (k - 1)] + 1 == k)
                cnt++;
        }
        return cnt;
    }
};