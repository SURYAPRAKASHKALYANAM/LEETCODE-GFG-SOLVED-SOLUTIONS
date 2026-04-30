class Solution {
public:
    void findNge(vector<int>& nge, vector<int>& nums) {
        int len = nums.size();
        stack<int> st;
        for (int i = len - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            nge[i] = st.empty() ? len : st.top();
            st.push(i);
        }
    }

    void findPge(vector<int>& pge, vector<int>& nums) {
        int len = nums.size();
        stack<int> st;
        for (int i = 0; i < len; i++) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int cnt = 0;
        int len = nums.size();
        vector<int> nge(len), pge(len);
        findNge(nge, nums);
        findPge(pge, nums);
        for (int i = 0; i < len; i++) {
            if (nums[i] >= left && nums[i] <= right) {
                int l = i - pge[i];
                int r = nge[i] - i;
                cnt += (l * r);
            }
        }
        return cnt;
    }
};