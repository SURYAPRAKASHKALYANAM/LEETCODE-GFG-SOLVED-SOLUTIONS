class Solution
{
    public:
        string shiftingLetters(string s, vector<int> &shifts)
        {
            long long sum = accumulate(shifts.begin(), shifts.end(), 1L)-1L;
            long long rem;
            for (auto i = 0; i < shifts.size(); i++)
            {
                rem = (s[i] - 'a' + sum);
                if (rem > 26)
                    rem = ((s[i] - 'a' + sum) % 26);
                s[i] = 'a' + rem;
                sum -= shifts[i];
            }
            return s;
        }
};