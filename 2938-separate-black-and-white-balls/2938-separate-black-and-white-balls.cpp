class Solution
{
    public:
        long long minimumSteps(string s)
        {
            int black = 0, white = 0, len = s.size();
            long long ans = 0;
            while (white < len)
            {
                while (white < len && s[white] == '1') white++;
                while (black < len && s[black] == '0') black++;
               	// cout<<white<<" "<<black<<endl;
                if (white < s.size() && white > black)
                {
                    ans += (white - black);
                    swap(s[white], s[black]);
                    white++, black++;
                }
                else white++;
            }
           	// cout<<s<<endl;
            return ans;
        }
};