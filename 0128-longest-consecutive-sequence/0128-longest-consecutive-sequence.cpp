class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            set<int> m;
           	// int max=INT_MIN,c=0;
            for (int i = 0; i < nums.size(); i++)
            {
                m.insert(nums[i]);
            }

           	//TC :O(LENGTH OF MAP)
           	// c=1;
           	// if(m.size()<=1) return m.size();
           	// for(int i=0;i < m.size()-1;i++)
           	// {
           	//     if(m[i]>0 && m[i+1]>0)
           	//     {
           	//         c++;
           	//         if(c>max) max=c;
           	//     }
           	//     else c=1;
           	//     if(c>max) max=c;
           	// } 

           	//optimal one TC O(N)
            int maxstreak = 0;
            for (auto i: nums)
            {
                int curr = i;
                if (m.find(curr - 1) == m.end())
                {
                    int currentstreak = 1;
                    while (m.find(curr + 1) != m.end())
                    {
                        currentstreak++;
                        curr++;
                    }
                    maxstreak = max(maxstreak, currentstreak);
                }
            }
            return maxstreak;
        }
};