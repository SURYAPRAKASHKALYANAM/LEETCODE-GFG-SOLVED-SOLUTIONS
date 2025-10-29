class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels,
                              int numWanted, int useLimit) {
        unordered_map<int, int> labelsUsed;
        int len = labels.size(), sum = 0, cnt = 0;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (values[j] > values[i]) {
                    swap(values[j], values[i]);
                    swap(labels[j], labels[i]);
                }
            }
            if (labelsUsed[labels[i]] < useLimit) {
                labelsUsed[labels[i]]++;
                sum += values[i];
                cnt++;
            }
            if (cnt == numWanted)
                break;
        }
        return sum;
    }
};