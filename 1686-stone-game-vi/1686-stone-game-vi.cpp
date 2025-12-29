class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        priority_queue<pair<int, int>> pq;
        int len = aliceValues.size();
        for (int i = 0; i < len; i++) {
            pq.push({aliceValues[i] + bobValues[i], i});
        }
        int aliceScore = 0, bobScore = 0;
        bool aliceTurn = true;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            if (aliceTurn) {
                aliceScore += aliceValues[it.second];
            } else {
                bobScore += bobValues[it.second];
            }
            aliceTurn = !aliceTurn;
        }
        if (aliceScore == bobScore)
            return 0;
        return aliceScore > bobScore ? 1 : -1;
    }
};