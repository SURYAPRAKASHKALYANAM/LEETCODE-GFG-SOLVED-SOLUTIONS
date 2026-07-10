class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, unordered_map<string, int>> tableOrders;
        set<string> dishes;
        for (auto& order : orders) {
            tableOrders[stoi(order[1])][order[2]]++;
            dishes.insert(order[2]);
        }
        vector<vector<string>> ans;
        ans.push_back({"Table"});
        ans[0].insert(ans[0].end(), dishes.begin(), dishes.end());
        for (auto table : tableOrders) {
            ans.push_back({to_string(table.first)});
            for (string dish : dishes) {
                ans.back().push_back(to_string(table.second[dish]));
            }
        }
        return ans;
    }
};