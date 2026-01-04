class Solution {
public:
    int find(int n) {
        int sum = 0, cnt = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                cnt++;
                sum += i;
                if ((n / i) != i) {
                    cnt++;
                    sum += (n / i);
                }
            }
            if (cnt > 4)
                return 0;
        }
        return cnt == 4 ? sum : 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        unordered_map<int, int> computed;
        int result = 0;
        for (int i : nums) {
            result += computed[i] ? computed[i] : (computed[i] = find(i));
        }
        return result;
    }
};