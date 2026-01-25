class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        // deque<int> q;
        // for (int& num : nums)
        //     if (num >= 0)
        //         q.push_back(num);
        // while (k--) {
        //     q.push_back(q.front());
        //     q.pop_front();
        // }
        // for (int& i : nums) {
        //     if (i < 0)
        //         continue;
        //     i = q.front();
        //     q.pop_front();
        // }
        // return nums;
        vector<int> tempNums;
        for (int& num : nums)
            if (num >= 0)
                tempNums.push_back(num);
        if (tempNums.size()) {
            k = k % tempNums.size();
            reverse(tempNums.rbegin(), tempNums.rend() - k);
            reverse(tempNums.rend() - k, tempNums.rend());
            reverse(tempNums.rbegin(), tempNums.rend());
            int st = 0;
            for (auto& i : nums) {
                if (i < 0)
                    continue;
                i = tempNums[st++];
            }
        }
        return nums;
    }
};