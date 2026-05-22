class Solution {
public:
    int find(int pos, vector<string>& words, vector<int> charCnt,
             vector<int>& score) {
        if (pos == words.size())
            return 0;
        int notTake = find(pos + 1, words, charCnt, score);
        int take = 0;
        vector<int> tempCnt = charCnt;
        for (int i = 0; i < words[pos].size(); i++) {
            if (charCnt[words[pos][i]-'a'] == 0) {
                take = 0;
                charCnt = tempCnt;
                break;
            }
            take += score[words[pos][i] - 'a'];
            charCnt[words[pos][i] - 'a']--;
        }
        take += find(pos + 1, words, charCnt, score);
        return max(take, notTake);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {
        vector<int> charCnt(26, 0);
        for (char ch : letters)
            charCnt[ch - 'a']++;
        return find(0, words, charCnt, score);
    }
};