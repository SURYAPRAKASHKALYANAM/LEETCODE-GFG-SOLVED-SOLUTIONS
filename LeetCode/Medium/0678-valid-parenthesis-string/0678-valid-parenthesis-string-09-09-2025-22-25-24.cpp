class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0;
        for (auto i : s) {
            if (i == '(') {
                minOpen++;
                maxOpen++;
            } else if (i == ')') {
                minOpen--;
                maxOpen--;
            } else {
                minOpen -= 1;
                maxOpen++;
            }
            if (minOpen < 0)
                minOpen = 0;
            if (maxOpen < 0)
                return false;
        }
        return minOpen == 0;
    }
};