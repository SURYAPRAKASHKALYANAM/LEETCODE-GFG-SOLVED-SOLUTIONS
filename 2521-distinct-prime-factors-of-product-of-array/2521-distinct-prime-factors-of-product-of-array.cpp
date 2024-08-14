class Solution
{
    public:
    set<int> primeFactors;
    void getPrimeFactors(int n)
    {
        while (n % 2 == 0)
        {
            primeFactors.insert(2);
            n /= 2;
        }
        for (int i = 3; i <= sqrt(n); i += 2)
        {
            while (n % i == 0)
            {
                primeFactors.insert(i);
                n /= i;
            }
        }
        if (n > 2)
        {
            primeFactors.insert(n);
        }
    }
    int distinctPrimeFactors(vector<int> &nums) {
        for(auto i:nums) getPrimeFactors(i);
        return primeFactors.size();
    }
};