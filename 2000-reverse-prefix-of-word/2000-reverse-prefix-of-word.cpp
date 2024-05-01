class Solution
{
    public:
        string reversePrefix(string word, char ch)
        {
            int ind = -1, left = 0;
            for (int i = 0; i < word.size(); i++)
            {
                if (word[i] == ch)
                {
                    ind = i;
                    break;
                }
            }
            if (ind == -1) return word;
            while (left < ind) swap(word[left++], word[ind--]);
            return word;
        }
};