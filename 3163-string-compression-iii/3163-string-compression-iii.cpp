class Solution
{
    public:
        string compressedString(string word)
        {
            int c = 1, pos = 0;
            string ans = "";
            while (pos < word.size())
            {
                while (c < 9 && pos + 1 < word.size() && word[pos] == word[pos + 1]) pos++, c++;
                ans += to_string(c) + word[pos];
                c = 1;
                pos++;
            }
            return ans;
        }
};