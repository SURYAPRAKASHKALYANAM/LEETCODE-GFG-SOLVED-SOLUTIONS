#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0;
        double min_y = 2e9, max_y = 0;

        for (const auto& s : squares) {
            double y = s[1];
            double l = s[2];
            totalArea += l * l;
            min_y = min(min_y, y);
            max_y = max(max_y, y + l);
        }

        double target = totalArea / 2.0;
        double low = min_y, high = max_y;

        for (int i = 0; i < 70; ++i) {
            double mid = low + (high - low) / 2.0;
            double currentAreaBelow = 0;

            for (const auto& s : squares) {
                double y = s[1];
                double l = s[2];
                double top = y + l;

                if (y >= mid)
                    continue;

                double h = min(mid, top) - y;
                currentAreaBelow += h * l;
            }

            if (currentAreaBelow < target) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return high;
    }
};