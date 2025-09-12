class Solution {
public:
    bool doesAliceWin(string s) {
        set<char> Vowels({'a', 'e', 'i', 'o', 'u'});
        for (char i : s) {
            if (Vowels.find(i) != Vowels.end())
                return true;
        }
        return false;
    }
};