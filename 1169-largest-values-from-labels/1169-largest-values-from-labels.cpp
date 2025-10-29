class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels,
                              int numWanted, int useLimit) {
        unordered_map<int, int> labelsUsed;
        int len = labels.size(), sum = 0, cnt = 0;
        // O(N^2)
        // for (int i = 0; i < len; i++) {
        //     for (int j = i + 1; j < len; j++) {
        //         if (values[j] > values[i]) {
        //             swap(values[j], values[i]);
        //             swap(labels[j], labels[i]);
        //         }
        //     }
        //     if (labelsUsed[labels[i]] < useLimit) {
        //         labelsUsed[labels[i]]++;
        //         sum += values[i];
        //         cnt++;
        //     }
        //     if (cnt == numWanted)
        //         break;
        // }
        // priority queue
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < len; i++)
            pq.push({values[i], labels[i]});
        while (!pq.empty() && numWanted) {
            auto it = pq.top();
            pq.pop();
            if (labelsUsed[it.second] < useLimit) {
                sum += it.first;
                numWanted--;
                labelsUsed[it.second]++;
            }
        }
        return sum;
    }
};