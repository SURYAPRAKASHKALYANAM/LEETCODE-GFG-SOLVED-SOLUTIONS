class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1,
                    int bx2, int by2) {
        int Area1 = abs(ax1 - ax2) * abs(ay1 - ay2);
        int Area2 = abs(bx1 - bx2) * abs(by1 - by2);
        if ((bx2 <= ax1 || bx1 >= ax2) || (by1 >= ay2 || by2 <= ay1)) {
            return Area1 + Area2;
        }
        int l = abs(max(ax1, bx1) - min(ax2, bx2));
        int w = abs(max(ay1, by1) - min(ay2, by2));
        return Area1 + Area2 - (l * w);
    }
};