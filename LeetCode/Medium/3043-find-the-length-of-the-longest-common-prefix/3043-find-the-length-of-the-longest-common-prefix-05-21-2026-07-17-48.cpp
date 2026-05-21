class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int max_num = 0;
        unordered_set<int> st;
        for (auto i : arr1) {
            while (i) {
                st.insert(i);
                i /= 10;
            }
        }
        for (auto i : arr2) {
            while (i) {
                if (st.count(i)) {
                    max_num = max(i, max_num);
                    break;
                }
                i /= 10;
            }
        }
        return max_num == 0 ? 0 : to_string(max_num).size();
    }
};