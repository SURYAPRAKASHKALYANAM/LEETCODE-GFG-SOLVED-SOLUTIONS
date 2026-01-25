class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        deque<int> q;
        for (int& num : nums)
            if (num >= 0)
                q.push_back(num);
        while (k--) {
            q.push_back(q.front());
            q.pop_front();
        }
        for (int& i : nums) {
            if (i < 0)
                continue;
            i = q.front();
            q.pop_front();
        }
        return nums;
    }
};