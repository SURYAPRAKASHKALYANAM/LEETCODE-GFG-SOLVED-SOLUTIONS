class Solution {
public:
    int nonAdjacent(vector<int>& nums) {
        int len = nums.size();
        int prev = 0, lastPrev = -1, curr;
        curr = prev = nums[0];
        for (int i = 1; i < len; i++) {
            if (lastPrev != -1)
                curr = max(lastPrev + nums[i], prev);
            else
                curr = max(prev, nums[i]);
            lastPrev = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& money) {
        int len = money.size();
        if (len == 1)
            return money[0];
        vector<int> temp1, temp2;
        for (int i = 0; i < len; i++) {
            if (i != 0)
                temp1.emplace_back(money[i]);
            if (i != (len - 1))
                temp2.emplace_back(money[i]);
        }
        return max(nonAdjacent(temp1), nonAdjacent(temp2));
    }
};