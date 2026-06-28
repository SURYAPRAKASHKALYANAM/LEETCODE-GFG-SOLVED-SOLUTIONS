class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(begin(arr), end(arr));
        arr[0] = 1;
        int max_ele = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (abs(arr[i] - arr[i - 1]) > 1) {
                arr[i] = arr[i - 1] + 1;
            }
            max_ele = max(max_ele, arr[i]);
        }
        return max_ele;
    }
};