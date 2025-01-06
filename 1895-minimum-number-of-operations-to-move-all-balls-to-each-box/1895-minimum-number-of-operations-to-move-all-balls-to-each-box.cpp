class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> prefix(n, 0), suffix(n, 0), ans(n, 0);
        int ones = 0;
        for (int i = 0; i < n; i++) {
            if (ones)
                prefix[i] = ((i > 0) ? prefix[i - 1] : 0) + ones;
            if (boxes[i] == '1')
                ones++;
        }
        ones = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (ones)
                suffix[i] = ((i < n - 1) ? suffix[i + 1] : 0) + ones;
            if (boxes[i] == '1')
                ones++;
        }
        for (int i = 0; i < n; i++)
            ans[i] = prefix[i] + suffix[i];
        return ans;
    }
};