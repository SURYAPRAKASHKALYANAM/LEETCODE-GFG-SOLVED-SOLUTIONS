class Solution {
public:
    bool beautiful(int n) {
        vector<int> nums(10);
        while (n) {
            nums[n % 10]++;
            n /= 10;
        }
        for (int i = 0; i <= 9; i++) {
            if (nums[i] > 0 && nums[i] != i)
                return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        while (1) {
            n++;
            if (beautiful(n))
                break;
        }
        return n;
    }
};