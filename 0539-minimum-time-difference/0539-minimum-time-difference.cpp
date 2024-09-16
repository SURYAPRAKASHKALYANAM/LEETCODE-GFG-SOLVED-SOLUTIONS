class Solution
{
    public:
        int findMinDifference(vector<string> &timePoints)
        {
            vector<int> time_in_min;
            for (auto i: timePoints)
            {
                int h1 = i[0] - '0', h2 = i[1] - '0', m1 = i[3] - '0', m2 = i[4] - '0';
                int HH = ((h1 *10) + (h2)), MM = m1 * 10 + m2;
                time_in_min.emplace_back(HH *60 + MM);
            }
            sort(time_in_min.begin(), time_in_min.end());
            int MIN_DIFF = INT_MAX;
            for (int i = 1; i < time_in_min.size(); i++) MIN_DIFF = min(abs(time_in_min[i] - time_in_min[i - 1]), MIN_DIFF);
            MIN_DIFF=min(MIN_DIFF,1440-time_in_min[time_in_min.size()-1]+time_in_min[0]);          
            return MIN_DIFF;
        }
};