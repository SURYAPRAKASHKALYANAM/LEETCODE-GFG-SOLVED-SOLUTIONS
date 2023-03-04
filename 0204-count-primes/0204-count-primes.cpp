class Solution
{
    public:
        int countPrimes(int n)
        {
            vector<bool> A(n, true);
            for (int i = 2; i * i <= n; i++)
            {
                for (int j = i * 2; j < n; j += i)
                {
                    if (A[j]) A[j] = false;
                }
            }
            int c = 0;
            for (int i = 2; i < n; i++)
                if (A[i] == true) c++;
            return c;
        }
};