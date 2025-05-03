class Solution {
public:
    int helper(vector<int> arr1, vector<int> arr2, int ele, int n) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (arr1[i] == ele)
                continue;
            else if (arr2[i] == ele)
                cnt++;
            else
                return -1;
        }
        return cnt;
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> counts(7, 0);
        int n = tops.size();
        for (int i = 0; i < n; i++) {
            counts[tops[i]]++;
            counts[bottoms[i]]++;
        }
        int max_freq = 0, freq_ele;
        for (int i = 1; i <= 6; i++) {
            if (counts[i] > max_freq) {
                max_freq = counts[i];
                freq_ele = i;
            }
        }
        return min(helper(bottoms, tops, freq_ele, n),
                   helper(tops, bottoms, freq_ele, n));
    }
};