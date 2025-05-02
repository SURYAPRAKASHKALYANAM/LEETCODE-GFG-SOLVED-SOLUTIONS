class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> lefttime(n, INT_MAX), righttime(n, INT_MAX);
        for (int i = n - 2; i >= 0; i--) {
            if (dominoes[i] == '.') {
                if (dominoes[i + 1] == 'L') {
                    lefttime[i] = 1;
                } else if (dominoes[i + 1] == '.' &&
                           lefttime[i + 1] != INT_MAX) {
                    lefttime[i] = lefttime[i + 1] + 1;
                }
            }
        }
        for (int i = 1; i < n; i++) {
            if (dominoes[i] == '.') {
                if (dominoes[i - 1] == 'R') {
                    righttime[i] = 1;
                } else if (dominoes[i - 1] == '.' &&
                           righttime[i - 1] != INT_MAX) {
                    righttime[i] = righttime[i - 1] + 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (lefttime[i] < righttime[i])
                dominoes[i] = 'L';
            else if (lefttime[i] > righttime[i])
                dominoes[i] = 'R';
        }
        return dominoes;
    }
};