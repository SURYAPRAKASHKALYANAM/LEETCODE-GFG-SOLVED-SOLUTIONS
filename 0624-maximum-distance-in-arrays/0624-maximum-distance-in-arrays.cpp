class Solution
{
    public:
        int maxDistance(vector<vector < int>> &arrays)
        {
            int max_diff = INT_MIN, min_so_far = 1e5, max_so_far = -1e5;
            for (int i = 0; i < arrays.size(); i++)
            {
                max_diff = max(max_diff, max(arrays[i].back() - min_so_far, max_so_far - arrays[i][0]));
                min_so_far = min(min_so_far, arrays[i][0]);
                max_so_far = max(max_so_far, arrays[i].back());
            }
            return max_diff;

           	// brute 
           	// int max_diff = INT_MIN;
           	// for (auto i = 0; i < arrays.size(); i++)
           	// {
           	//     for (auto j = 0; j < arrays.size(); j++)
           	//     {
           	//         if (i != j) max_diff = max(max_diff, abs(arrays[i].back() - arrays[j][0]));
           	//     }
           	// }
           	// return max_diff;
        }
};