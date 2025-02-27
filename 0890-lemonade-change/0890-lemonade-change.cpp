class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int tens = 0, fives = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 20) {
                if (tens > 0 && fives > 0)
                    tens--, fives--;
                else if (fives >= 3)
                    fives -= 3;
                else
                    return false;
            } else if (bills[i] == 10) {
                if (fives > 0) {
                    fives--;
                    tens++;
                } else
                    return false;
            } else
                fives++;
        }
        return true;
    }
};