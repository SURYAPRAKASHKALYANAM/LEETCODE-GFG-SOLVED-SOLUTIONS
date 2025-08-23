class Solution {
public:
    void generate(vector<vector<int>>& ans, vector<int>& sub, int target,
                  int currlen, int currEle) {
        if (currlen == 0) {
            if (target == 0)
                ans.emplace_back(sub);
            return;
        }
        if (target <= 0 || currEle > 9)
            return;
        sub.push_back(currEle);
        generate(ans, sub, target - currEle, currlen - 1, currEle + 1);
        sub.pop_back();
        generate(ans, sub, target, currlen, currEle + 1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        // your code goes here
        vector<vector<int>> ans;
        vector<int> sub;
        generate(ans, sub, n, k, 1);
        return ans;
    }
};