class Solution
{
    public:
        int minimizeXor(int num1, int num2)
        {
            if (num1 == num2)
                return num1;
            int cnt = __builtin_popcount(num2);
            int max_bit = 1, ans = 0;
            while (max_bit < num1)
                max_bit <<= 1;
            while (cnt > 0)
            {
                if (max_bit & num1)
                {
                    ans |= max_bit;
                    cnt--;
                }
                if (max_bit == 0)
                {
                    int fill = 1;
                    while (cnt > 0)
                    {
                        if (!(fill & ans))
                        {
                            ans |= fill;
                            cnt--;
                        }
                        fill <<= 1;
                    }
                }
                max_bit >>= 1;
            }
            return ans;
        }
};