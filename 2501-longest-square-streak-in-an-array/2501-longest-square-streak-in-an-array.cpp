class Solution
{
    public:
        int longestSquareStreak(vector<int> &nums)
        {
            map < long long, int> visited, have;
            sort(nums.begin(), nums.end());
            int max_len = -1;
            for (int i: nums) have[i] = 1;
            for (int i = 0; i < nums.size(); i++)
            {
                long long ele = nums[i];
                if (!visited[ele])
                {
                    int cnt = 0;
                    while (have[ele] && !visited[ele])
                    {
                        visited[ele] = 1;
                        ele *= ele;
                        cnt++;
                    }
                    if (cnt > 1) max_len = max(cnt, max_len);
                }
            }
            return max_len;
            //OPTIMAL DP
           	//     map<int, int>mp;
           	// sort(nums.begin(), nums.end());
           	// int res = -1;
           	// for(int num: nums) {
           	//     int _sqrt = sqrt(num);
           	//     if(_sqrt *_sqrt == num && mp.find(_sqrt)!=mp.end()) {
           	//         mp[num] = mp[_sqrt]+1;
           	//         res = max(res, mp[num]);
           	//     } else mp[num] = 1;
           	// }
           	// return res;
        }
};