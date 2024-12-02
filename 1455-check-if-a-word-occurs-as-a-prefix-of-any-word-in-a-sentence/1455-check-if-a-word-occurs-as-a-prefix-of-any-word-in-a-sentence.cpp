class Solution
{
    public:
        int isPrefixOfWord(string sentence, string searchWord)
        {
            int start = 0, end = 0, n = sentence.size(), sen = searchWord.size(), wc = 1;
            for (; end < n; end++)
            {
                if (sentence[end] == ' ' || end == n - 1)
                {
                    int curr = 0;
                    while (curr < sen && searchWord[curr] == sentence[start]) curr++, start++;
                    if (curr == sen) return wc;
                    start = end + 1;
                    wc++;
                }
            }
            return -1;
        }
};