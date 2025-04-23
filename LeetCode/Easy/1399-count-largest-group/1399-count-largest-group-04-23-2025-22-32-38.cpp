class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> hash(37);
        int max_hash = 0;
        for (int i = 1; i <= n; i++) {
            int temp = i, s = 0;
            while (temp) {
                s += (temp % 10);
                temp /= 10;
            }
            hash[s]++;
        }
        max_hash = *max_element(begin(hash), end(hash));
        return count(hash.begin(), hash.end(), max_hash);
    }
};