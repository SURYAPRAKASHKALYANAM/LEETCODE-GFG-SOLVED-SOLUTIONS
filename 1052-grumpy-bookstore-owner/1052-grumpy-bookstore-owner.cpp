class Solution
{
    public:
        int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
        {
            int tikadam = 0, max_tik = 0;
            int sum = 0;
            for (int i = 0; i < minutes; i++)
            {
                if (grumpy[i] == 0)	// not grumpy
                {

                    sum += customers[i];
                }
                else tikadam += customers[i];	// else let use tecnq
            }
            max_tik = tikadam;
            int begin = 0, end = minutes;
            while (begin < end && end < customers.size())
            {
                if (grumpy[begin] == 1)
                {
                    tikadam -= customers[begin];
                }
                if (grumpy[end] == 1) tikadam += customers[end];
                else sum += customers[end];
                max_tik = max(max_tik, tikadam);
                begin++;
                end++;
            }
            return sum + max_tik;
        }
};