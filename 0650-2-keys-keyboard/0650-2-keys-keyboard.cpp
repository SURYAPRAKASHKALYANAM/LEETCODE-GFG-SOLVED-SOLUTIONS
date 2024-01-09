class Solution
{
    public:
        int minSteps(int n)
        {
            int s = 0, k = n - 1;
            while (n > 1)
            {
                while (n % k != 0) k--;
                s += (n / k);
                n = k;
                k--;
            }
            return s;
        }
};