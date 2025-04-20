class Solution {
public:
    int numRabbits(vector<int>& answers) {
        // vector<int> counts(10e3, 0);
        unordered_map<int, int> counts;
        for (auto rabits : answers)
            counts[rabits]++;
        int min_rab = counts[0];
        for (auto i : counts) {
            int said = i.first, cnt = i.second;
            if (said) {
                min_rab += (cnt / (said + 1)) * (said + 1) +        // seen each other
                           ((cnt % (said + 1) > 0 ? 1 : 0) * said + // seen different
                           (cnt % (said + 1) > 0));                // self
            }
        }
        // for (int i = 1; i <= 1000; i++) {
        //     if (counts[i]) {
        //         cnt += (counts[i] / (i + 1)) * (i + 1) + // seen each other
        //                ((counts[i] % (i + 1) > 0 ? 1 : 0) * i + // seen
        //                different
        //                 (counts[i] % (i + 1) > 0)); // self
        //     }
        // }
        return min_rab;
    }
};