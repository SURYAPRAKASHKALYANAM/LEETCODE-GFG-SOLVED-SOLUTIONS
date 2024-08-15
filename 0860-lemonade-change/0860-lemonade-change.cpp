class Solution
{
    public:
        bool lemonadeChange(vector<int> &bills)
        {
            int tens = 0, fives = 0, twenties = 0;
            for (auto i: bills)
            {
                (i == 5) ? fives++ : ((i == 10) ? tens++ : twenties++);
                if (i == 20)
                {
                    if (tens && fives) tens--, fives--;
                    else if (fives >= 3) fives -= 3;
                    else return false;
                }
                else if (i == 10)
                {
                    if (fives) fives--;
                    else return false;
                }
            }
            return true;
        }
};