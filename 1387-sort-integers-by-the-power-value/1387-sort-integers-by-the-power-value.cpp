class Solution {
public:
    unordered_map<long long, int> ops;

    int findOps(long long n) {
        if (n == 1)
            return 0;

        if (ops.count(n))
            return ops[n];

        if (n & 1)
            return ops[n] = 1 + findOps(3 * n + 1);
        else
            return ops[n] = 1 + findOps(n / 2);
    }

    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> vals;

        for (int i = lo; i <= hi; i++) {
            vals.push_back({findOps(i), i});
        }

        sort(vals.begin(), vals.end());

        return vals[k - 1].second;
    }
};