class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, ele1 = INT_MIN, ele2 = INT_MIN;
        for (int i : nums) {
            if (cnt1 == 0 && i != ele2) {
                ele1 = i;
                cnt1++;
            } else if (cnt2 == 0 && i != ele1) {
                ele2 = i;
                cnt2++;
            } else if (ele1 == i)
                cnt1++;
            else if (ele2 == i)
                cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        int len = nums.size() / 3 + 1;
        cnt1 = 0, cnt2 = 0;
        for (auto i : nums) {
            cnt1 += (i == ele1);
            cnt2 += (i == ele2);
        }
        vector<int> ans;
        if (cnt1 >= len)
            ans.push_back(ele1);
        if (cnt2 >= len)
            ans.push_back(ele2);
        return ans;
    }
};