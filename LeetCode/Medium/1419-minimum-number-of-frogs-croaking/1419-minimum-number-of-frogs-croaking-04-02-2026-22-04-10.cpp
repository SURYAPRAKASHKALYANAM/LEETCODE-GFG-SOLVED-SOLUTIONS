class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        string s = "croak";
        int cnts[5] = {};
        int frogs = 0, max_frogs_singing = 0;
        for (char i : croakOfFrogs) {
            int n = s.find(i);
            cnts[n]++;
            if (n == 0) {
                max_frogs_singing = max(max_frogs_singing, ++frogs);
            } else if (--cnts[n - 1] < 0)
                return -1;
            else if (n == 4)
                frogs--;
        }
        // me while coding this from the begining to end... trr trr.. trr trr
        // at the end ortubac helped
        return frogs == 0 ? max_frogs_singing : -1;
    }
};