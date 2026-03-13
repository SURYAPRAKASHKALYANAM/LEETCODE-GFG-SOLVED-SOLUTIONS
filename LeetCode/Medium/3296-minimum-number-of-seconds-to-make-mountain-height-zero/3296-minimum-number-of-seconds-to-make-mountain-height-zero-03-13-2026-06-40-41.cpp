class Solution {
public:
    long long maxHeight(long long w, long long y) {
        long double max_val = (2.0L * y) / w;
        long long n = (-1.0 + sqrt(1.0 + 4.0 * max_val)) / 2.0;
        return n;
    }
    bool canMake(int mountainHeight, vector<int>& workerTimes,
                 long long currT) {
        for (int& w : workerTimes) {
            mountainHeight -= maxHeight(1LL * w, currT);
            if (mountainHeight <= 0)
                return true;
        }
        return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long min_w = *min_element(workerTimes.begin(), workerTimes.end());
        long long minT = 0,maxT = min_w * (1LL* mountainHeight * (1LL*mountainHeight + 1LL) / 2LL),currT;
        while (minT <= maxT) {
            currT = minT + (maxT - minT) / 2;
            if (canMake(mountainHeight, workerTimes, currT)) {
                maxT = currT - 1;
            } else
                minT = currT + 1;
        }
        return minT;
    }
};