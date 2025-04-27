class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start = 0, end = 0, n = fruits.size();
        int curr = 0, max_fruits = 0;
        // unordered_map<int, int> seen;
        vector<int> seen(n,0);
        while (end < n) {
            while (curr <= 2 && end < n) {
                if (curr == 2 && !seen[fruits[end]]) {
                    break;
                } else if (!seen[fruits[end]])
                    curr++;
                seen[fruits[end]]++;
                end++;
            }
            max_fruits = max(max_fruits, end - start);
            while (curr == 2 && start < end) {
                --seen[fruits[start]];
                if (seen[fruits[start]] == 0)
                    curr--;
                start++;
            }
        }
        return max_fruits;
    }
};