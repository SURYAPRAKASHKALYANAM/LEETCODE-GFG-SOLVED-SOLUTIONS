class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> y_counts;
        
        for (const auto& point : points) {
            y_counts[point[1]]++;
        }

        long long MOD = 1e9 + 7;
        long long total_segments_so_far = 0;
        long long result = 0;

        for (auto& entry : y_counts) {
            long long n = entry.second;

            if (n < 2) continue;

            long long current_segments = (n * (n - 1)) / 2;
            
            current_segments %= MOD;

            result = (result + (current_segments * total_segments_so_far)) % MOD;

            total_segments_so_far = (total_segments_so_far + current_segments) % MOD;
        }

        return (int)result;
    }
};