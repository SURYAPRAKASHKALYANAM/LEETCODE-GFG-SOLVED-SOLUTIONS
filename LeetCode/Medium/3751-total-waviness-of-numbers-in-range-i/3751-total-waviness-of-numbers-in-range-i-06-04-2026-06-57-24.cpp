class Solution {
public:
    int waviness(int n) {
        int prev = -1, prev2 = -1, curr;
        int cnt = 0;
        while (n) {
            curr = n % 10;
            if (prev != -1 && prev2 != -1) {
                if ((prev2 > prev && prev < curr) ||
                    (prev2 < prev && prev > curr))
                    cnt++;
            }
            prev2 = prev;
            prev = curr;
            n /= 10;
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int cnt = 0;
        for (int i = num1; i <= num2; i++) {
            cnt += waviness(i);
        }
        return cnt;
    }
};