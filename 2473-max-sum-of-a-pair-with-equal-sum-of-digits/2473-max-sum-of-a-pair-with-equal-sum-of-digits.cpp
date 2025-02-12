class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        map<int, priority_queue<int>> m;
        int ans = -1;
        for (auto i : nums)
            m[digitSum(i)].push(i);
        for (auto ele : m) {
            auto q = ele.second;
            if (q.size() >= 2) {
                int curr = q.top();
                q.pop();
                ans = max(ans, curr + q.top());
            }
        }
        return ans;
    }
};