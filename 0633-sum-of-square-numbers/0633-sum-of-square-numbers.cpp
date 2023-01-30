class Solution
{
    public:
        bool judgeSquareSum(int c)
        {
            if(c==0) return 1;
            long long int low1 = 0, high1 = pow(c, 0.5), s;
            while (high1 > 0 && low1 <c)
            {
                s = low1 *low1 + high1 * high1;
                if (s==c) return 1;
                if(s<c) low1++;
                else high1--;
            }
            return 0;
        }
};