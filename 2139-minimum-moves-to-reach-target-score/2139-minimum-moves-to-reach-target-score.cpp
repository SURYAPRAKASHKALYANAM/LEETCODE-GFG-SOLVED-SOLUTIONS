class Solution
{
    public:
        int minMoves(int target, int maxDoubles)
        {
            int rem = target, cnt = 0;
            while (rem > 1)
            {
                if(rem&1) cnt++,rem--;
                else
                {
                    if(maxDoubles>0)
                    {
                        rem=rem/2;
                        cnt++;
                        maxDoubles--;
                    }
                    else 
                    {
                        cnt+=rem-1;
                        break;
                    }
                }
            }
            return cnt;
        }
};