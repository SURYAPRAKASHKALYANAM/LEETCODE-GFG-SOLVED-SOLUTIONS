class Solution
{
    public:
        bool escapeGhosts(vector<vector < int>> &ghosts, vector< int > &target)
        {
            double dis = DBL_MAX;
            for (auto i: ghosts)
            {
                dis = min(dis, (double) abs(i[0] - target[0]) + (double) abs(i[1] - target[1]));
            }
            return dis > (double) (abs(target[0]) + abs(target[1]));
        }
};