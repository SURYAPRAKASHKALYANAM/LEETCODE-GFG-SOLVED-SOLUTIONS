class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> Visited, Index;
        for (auto i = 0; i < A.size(); i++)
            Index[A[i]] = i;
        int cnt = 0;
        vector<int> ans;
        for (int i = 0; i < B.size(); i++) {
            if (Index[B[i]] <= i)
                cnt++;
            if (Visited[A[i]])
                cnt++;
            ans.emplace_back(cnt);
            Visited[B[i]] = 1;
        }
        return ans;
    }
};