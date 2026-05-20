class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> counts(n + 1, 0), res;
        int seen = 0;
        for (int i = 0; i < n; i++) {
            counts[A[i]]++;
            if (counts[A[i]] == 2)
                seen++;
            counts[B[i]]++;
            if (counts[B[i]] == 2)
                seen++;
            res.emplace_back(seen);
        }
        return res;
    }
};