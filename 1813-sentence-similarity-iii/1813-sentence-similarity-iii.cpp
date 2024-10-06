class Solution
{
    public:
    bool helper(vector<string> &s1, vector<string> &s2)
    {
        if (s2.size() == 1) return s1.front() == s2.front() || s1.back() == s2.front();
        int i = 0, j = s1.size() - 1;
        int start = 0, end = s2.size() - 1;
        while (i < s1.size() && start < s2.size() && s1[i] == s2[start]) i++, start++;
        while (j >= 0 && end >= 0 && s1[j] == s2[end]) j--, end--;
        return start > end;
    }
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        vector<string> s1, s2;
        stringstream ss1(sentence1), ss2(sentence2);
        string s;
        while (ss1 >> s) s1.emplace_back(s);
        while (ss2 >> s) s2.emplace_back(s);
        if (s1.size() > s2.size()) return helper(s1, s2);
        return helper(s2, s1);
    }
};