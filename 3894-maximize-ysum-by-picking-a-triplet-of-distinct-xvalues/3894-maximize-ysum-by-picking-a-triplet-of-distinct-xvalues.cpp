class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        set<int> st;
        priority_queue<pair<int, int>> pq;
        int len = x.size();
        for (int i = 0; i < len; i++)
            pq.push({y[i], x[i]});
        int sum = 0;
        while (!pq.empty() && st.size() < 3) {
            auto it = pq.top();
            pq.pop();
            if (st.find(it.second) != st.end())
                continue;
            st.insert(it.second);
            sum += it.first;
        }
        return st.size() == 3 ? sum : -1;
    }
};