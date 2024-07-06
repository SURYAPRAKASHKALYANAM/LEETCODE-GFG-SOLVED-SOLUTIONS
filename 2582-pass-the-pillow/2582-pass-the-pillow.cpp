class Solution
{
    public:
        int passThePillow(int n, int time)
        {
            if (time < n) return time + 1;
            int tot = 2 *n - 2;
            int rem = time % tot;
            if (rem < n - 1) return rem + 1;
            else return n-(rem-n+1);
        }
};