class Solution
{
    public:
        int commonFactors(int a, int b)
        {
            int mini = min(a, b);
            int maxi = max(a, b);
            int c = 1;
            for (int i = 2; i <= mini; i++)
            {
                if (mini % i == 0 && maxi % i == 0) c++;
            }
            return c;
        }
};