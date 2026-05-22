class Solution {
public:
    int find(int pos, const vector<vector<int>>& wordCounts,
             const vector<int>& wordScores, vector<int>& charCnt) {

        if (pos == wordCounts.size()) {
            return 0;
        }

        int max_score = find(pos + 1, wordCounts, wordScores, charCnt);

        bool canTake = true;
        for (int i = 0; i < 26; i++) {
            if (charCnt[i] < wordCounts[pos][i]) {
                canTake = false;
                break;
            }
        }

        if (canTake) {
            for (int i = 0; i < 26; i++) {
                charCnt[i] -= wordCounts[pos][i];
            }

            int takeScore = wordScores[pos] +
                            find(pos + 1, wordCounts, wordScores, charCnt);
            max_score = max(max_score, takeScore);

            for (int i = 0; i < 26; i++) {
                charCnt[i] += wordCounts[pos][i];
            }
        }

        return max_score;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {
        vector<int> charCnt(26, 0);
        for (char ch : letters) {
            charCnt[ch - 'a']++;
        }

        int n = words.size();

        vector<vector<int>> wordCounts(n, vector<int>(26, 0));
        vector<int> wordScores(n, 0);

        for (int i = 0; i < n; i++) {
            for (char ch : words[i]) {
                wordCounts[i][ch - 'a']++;
                wordScores[i] += score[ch - 'a'];
            }
        }

        return find(0, wordCounts, wordScores, charCnt);
    }
};