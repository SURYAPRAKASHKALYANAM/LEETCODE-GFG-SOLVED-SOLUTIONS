class Solution
{
    public:
        bool canMakeSubsequence(string str1, string str2)
        {
            int point1 = 0, point2 = 0, n1 = str1.size(), n2 = str2.size();
            while (point2 < n2 && point1 < n1)
            {
                if (str1[point1] == 'z' && str2[point2] == 'a')
                {
                    point1++, point2++;
                    continue;
                }
                if (str1[point1] == str2[point2] || str1[point1] + 1 == str2[point2]) point1++, point2++;
                else point1++;
            }
            return n2 == point2;
        }
};