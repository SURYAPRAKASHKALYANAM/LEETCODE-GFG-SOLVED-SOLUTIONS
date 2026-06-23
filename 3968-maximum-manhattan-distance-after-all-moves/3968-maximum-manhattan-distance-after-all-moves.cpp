class Solution {
public:
    int maxDistance(string moves) {
        int x = 0, y = 0, wild = 0;
        for (char ch : moves) {
            if (ch == 'U')
                y++;
            else if (ch == 'D')
                y--;
            else if (ch == 'L')
                x--;
            else if (ch == 'R')
                x++;
            else
                wild++;
        }
        return wild + abs(x) + abs(y);
    }
};