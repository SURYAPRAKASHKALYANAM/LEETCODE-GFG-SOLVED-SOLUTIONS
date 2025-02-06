class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int cnt = 0;
        unordered_map<int, int> products;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++)
                products[nums[i] * nums[j]]++;
        }
        for (auto i : products)
            cnt += (((i.second - 1) * i.second) / 2) * 8;
        return cnt;
    }
};