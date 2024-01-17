class Solution
{
    public:
        int brokenCalc(int startValue, int target)
        {
            if(target<startValue) return startValue-target;
            int cnt = 0, temp = target;
            while (temp > startValue)
            {
                if (temp % 2 == 0)
                {
                    if (temp / 2 >=startValue)
                    {
                        temp = temp / 2;
                        cnt++;
                    }
                    else temp++;
                }
                else
                {
                    temp++;
                    cnt++;
                }
            }
            return cnt;
        }
};