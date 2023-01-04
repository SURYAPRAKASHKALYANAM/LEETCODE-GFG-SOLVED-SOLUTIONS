class Solution
{
    public:
        int minimumRounds(vector<int> &tasks)
        {
            unordered_map<int, int> mp;
            int round=0,freq;
            for (auto i:tasks) mp[i]++;
            for(auto i:mp)
            {
                freq=i.second;
                if(freq==1) return -1;
                else if(freq%3==0) round+=(freq/3);
                else round+=(freq/3)+1;
            }
            return round;

        }
};