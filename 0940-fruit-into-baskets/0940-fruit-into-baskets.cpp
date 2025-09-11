class Solution {
   public:
    int totalFruit(vector<int>& fruits) {
        int len = fruits.size();
        int l = 0, r = 0;
        unordered_map<int, int> seen;
        int max_fruits = 0;
        while (r < len) {
            seen[fruits[r]]++;
            while (seen.size()>2) {
                seen[fruits[l]]--;
                if (seen[fruits[l]] == 0) {
                    seen.erase(fruits[l]);
                }
                l++;
            }
            max_fruits = max(max_fruits, r - l + 1);
            r++;
        }
        return max_fruits;
    }
};