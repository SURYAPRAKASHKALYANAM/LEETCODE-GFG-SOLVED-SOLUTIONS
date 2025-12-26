class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int len = arr.size();
        priority_queue<int> q;
        unordered_map<int, int> cnts;
        for (int& i : arr)
            cnts[i]++;
        for (auto [key, val] : cnts)
            q.push(val);
        int cnt = 0, ele = 0;
        while (cnt < (len / 2)) {
            cnt += q.top();
            ele++;
            q.pop();
        }
        return ele;
    }
};