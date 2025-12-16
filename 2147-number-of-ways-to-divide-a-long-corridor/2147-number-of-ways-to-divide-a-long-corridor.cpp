class Solution {
public:
    int numberOfWays(string corridor) {
        int total = count(corridor.begin(), corridor.end(), 'S');
        if ((total & 1) || total == 0)
            return 0;
        int mod = 1e9 + 7;
        long long ans = 1;
        int plants = 1, seats = 0;
        int len = corridor.size();
        int start = 0;
        while (start < len) {
            seats = 0;
            while (start < len && seats < 2) {
                seats += (corridor[start++] == 'S');
            }
            if (seats == 2) {
                while (start < len && corridor[start] != 'S') {
                    plants++;
                    start++;
                }
                if (start != len)
                    ans = (ans * (plants)) % mod;
                plants = 1;
            }
        }
        return ans;
    }
};