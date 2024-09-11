class Solution
{
    public:
        int minBitFlips(int start, int goal)
        {
            int cnt = 0;
            while (start > 0 && goal > 0)
            {
                if (start % 2 != goal % 2) cnt++;
                start /= 2;
                goal /= 2;
            }
            while (start) cnt += (start % 2), start /= 2;
            while (goal) cnt += (goal % 2), goal /= 2;
            return cnt;
        }
};