class Solution
{
    public:
        long long dividePlayers(vector<int> &skill)
        {
            long long cnt = 0, sum = accumulate(skill.begin(), skill.end(), 0), n = skill.size() / 2;
            unordered_map<int, int> m;
            int need = sum / n;
            if(sum%n) return -1;
            for (auto i: skill)
            {
                m[i]++;
                int req = need - i;
                if (m[req]) cnt += (req *i), m[i]--, m[req]--, n--;
            }
            return n != 0 ? -1 : cnt;
        }
};