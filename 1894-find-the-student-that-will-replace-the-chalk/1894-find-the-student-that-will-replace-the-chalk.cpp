class Solution
{
    public:
        int chalkReplacer(vector<int> &chalk, int k)
        {
            long long sum =0;
            for(auto i:chalk) sum+=i;
            int leftover = k % sum, i = 0;
            for (; i < chalk.size(); i++)
            {
                if (leftover >= chalk[i]) leftover -= chalk[i];
                else break;
            }
            return i;
        }
};