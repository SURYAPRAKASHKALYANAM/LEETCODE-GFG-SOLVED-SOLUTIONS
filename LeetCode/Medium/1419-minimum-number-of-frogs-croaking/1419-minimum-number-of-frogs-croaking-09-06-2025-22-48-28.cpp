class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        string s = "croak";
        unordered_map<char, int> cnts;
        int total = 0, unique = 0;
        for (int i = 0; i < len; i++) {
            cnts[i]++;
            
        }
        return (total + unique) == 0 ? -1 : (total + unique);
    }
};