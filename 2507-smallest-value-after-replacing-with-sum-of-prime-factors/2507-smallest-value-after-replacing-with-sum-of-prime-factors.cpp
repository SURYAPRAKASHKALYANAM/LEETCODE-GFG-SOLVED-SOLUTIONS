class Solution
{
    public:
        int primefactorsum(int n)
        {
            int s = 0;
            while ((n & 1) == 0)
            {
                s += 2;
                n = n / 2;
            }
            for (int i = 3; i <= sqrt(n); i += 2)
            {
                while (n % i == 0)
                {
                    s += i;
                    n = n / i;
                }
            }
            if (n > 2) s += n;
            return s;
        }
    int smallestValue(int n)
    {
        unordered_map<int, int> m;
        m[n] = 1;
        int p = primefactorsum(n), mi = n;
        mi = min(p, mi);
        while (!m[p])
        {
            m[p] = 1;
            p = primefactorsum(p);
            mi = min(p, mi);
        }

        return mi;
    }
};