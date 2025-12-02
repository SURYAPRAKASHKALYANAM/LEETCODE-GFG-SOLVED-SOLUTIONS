class Solution {
public:
    long long factorial(long long n) {
        return n == 0 ? 1 : n * factorial(n - 1);
    }
    int compute(int n) {
        return n <= 1 ? 0
                      : factorial((long long)n) /
                            (2LL * factorial((long long)n - 2LL));
    }
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> cnts;
        for (auto point : points)
            cnts[point[1]]++;
        for (auto& i : cnts) {
            i.second = compute(i.second);
        }
        int ans = 0, mod = 1e9 + 7;
        // (a+b+c)^2 = a2+b2+c2 + 2(ab+bc+ca)
        // ab+bc+ca = ((a+b+c)^2 - (a2+b2+c2))/2;
        long long sum = 0LL , sqSum = 0LL;
        for (auto& i : cnts) {
            sum+=i.second;
            sqSum+=(1LL*i.second*i.second);
        }
        return ((((sum*sum)) - (sqSum))/2)%mod;;
    }
};