class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long start = 0, cnt = 0;
        multiset<int> st;

        for (int end = 0; end < n; ++end) {
            st.insert(nums[end]);
            while (start <= end) {
                long long mini = *st.begin();
                long long maxi = *st.rbegin();
                long long cost = (maxi - mini) * (end - start + 1);

                if (cost > k) {
                    st.erase(st.find(nums[start]));
                    start++;
                } else {
                    break;
                }
            }
            cnt += (end - start + 1);
        }

        return cnt;
    }
};