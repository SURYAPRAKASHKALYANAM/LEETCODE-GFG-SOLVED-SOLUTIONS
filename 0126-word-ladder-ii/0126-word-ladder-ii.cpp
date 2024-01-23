class Solution
{
    private:
    vector<vector < string>> ans;
    unordered_map<string, int> m;
    string b;
    void dfs(string word, vector<string> &seq)
    {
        if (word == b)
        {
            reverse(seq.begin(), seq.end());
            ans.emplace_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = m[word];
        for (int i = 0; i < word.size(); i++)
        {
            char org = word[i];
            for (char c = 'a'; c <= 'z'; c++)
            {
                word[i] = c;
                if (m.find(word) != m.end() && m[word] + 1 == steps)
                {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = org;
        }
    }
    public:
        vector<vector < string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
        {
            b = beginWord;
            unordered_set<string> s(wordList.begin(), wordList.end());
            queue<string> q;
            m[beginWord] = 1;
            q.push(beginWord);
            s.erase(beginWord);
            int sz = beginWord.size();
            while (!q.empty())
            {
                string word = q.front();
                int steps = m[word];
                q.pop();
                if (word == endWord) break;
                for (int i = 0; i < sz; i++)
                {
                    char org = word[i];
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        word[i] = c;
                        if (s.find(word) != s.end())
                        {
                            m[word] = steps + 1;
                            q.push(word);
                            s.erase(word);
                        }
                    }
                    word[i] = org;
                }
            }
            if (m.find(endWord) != m.end())
            {
                vector<string> seq;
                seq.push_back(endWord);
                dfs(endWord, seq);
            }
            return ans;
        }
};