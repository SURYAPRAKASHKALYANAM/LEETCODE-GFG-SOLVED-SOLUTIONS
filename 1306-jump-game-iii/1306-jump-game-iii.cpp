class Solution {
public:
    unordered_set<int> vis;
    bool canReach(vector<int>& arr, int start) {
        if (start < 0 || start >= arr.size())
            return false;
        if (vis.count(start))
            return false;
        vis.insert(start);
        if (arr[start] == 0)
            return true;
        return canReach(arr, start + arr[start]) ||
               canReach(arr, start - arr[start]);
    }
};