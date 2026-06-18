class Solution
{
    public:
        double angleClock(int hour, int minutes)
        {
            double ans = abs(30 * (double)hour - ((double)(11 *(double)minutes) / (double)2));
            return min(ans, (double)abs(360 - ans));
        }
};