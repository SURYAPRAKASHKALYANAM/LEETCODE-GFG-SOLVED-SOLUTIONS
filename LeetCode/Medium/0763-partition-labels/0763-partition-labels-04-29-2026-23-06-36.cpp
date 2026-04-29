class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastPos(26, 0);
        int len = s.size();
        for (int i = 0; i < len; i++) {
            lastPos[s[i] - 'a'] = i;
        }

        int maxLast = -1;
        int start = -1;
        vector<int> partitions;
        for (int i = 0; i < len; i++) {
            maxLast = max(maxLast, lastPos[s[i] - 'a']);
            if (maxLast == i) {
                partitions.push_back(i - start);
                start = i;
            }
        }
        return partitions;
    }
};