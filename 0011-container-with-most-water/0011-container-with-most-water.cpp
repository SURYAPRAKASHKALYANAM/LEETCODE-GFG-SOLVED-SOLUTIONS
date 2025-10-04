class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, max_ans = INT_MIN;
        while (left < right) {
            max_ans = max(min(height[left], height[right]) * (right - left), max_ans);
            if (height[left] > height[right])
                right--;
            else
                left++;
        }
        return max_ans;
    }
};