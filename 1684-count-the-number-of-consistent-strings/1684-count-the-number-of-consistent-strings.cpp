class Solution
{
    public:
        int countConsistentStrings(string allowed, vector<string> &words)
        {
            unordered_map<int, int> has;
            int cnt = 0;
            for (auto i: allowed) has[i - 'a']++;
            for (auto word: words)
            {
                bool is = 1;
                for(auto i:word) if(!has[i-'a']) {is=0;break;}
                cnt += is;
            }
            return cnt;
        }
};