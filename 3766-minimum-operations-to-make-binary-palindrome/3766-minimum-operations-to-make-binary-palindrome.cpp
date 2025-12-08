class Solution {
public:
    int rev(int n) {
        int revNum = 0;
        while (n) {
            revNum = revNum * 2 + (n % 2);
            n /= 2;
        }
        return revNum;
    }
    int helper(int n) {
        int temp = n;
        while (temp) {
            if (rev(temp) == temp)
                break;
            temp--;
        }
        int dis1 = n - temp;
        temp = n;
        while (n) {
            if (temp == rev(temp))
                break;
            temp++;
        }
        return min(dis1, temp - n);
    }
    vector<int> minOperations(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len);
        for (int i = 0; i < len; i++) {
            ans[i] = helper(nums[i]);
        }
        return ans;
    }
};