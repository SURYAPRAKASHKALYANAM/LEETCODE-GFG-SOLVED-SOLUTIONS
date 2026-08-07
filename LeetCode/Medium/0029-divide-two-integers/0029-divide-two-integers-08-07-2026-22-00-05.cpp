class Solution {
public:
    int divide(int dividend, int divisor) {
        // your code goes here
        // generic Math Approach O (DIVIDE/DIVISOR)
        /*
        bool isPositive = true;
        if (dividend >= 0 && divisor < 0)
            isPositive = false;
        if (dividend <= 0 && divisor > 0)
            isPositive = false;
        long absdividend = abs((long)dividend);
        long absdivisor = abs((long)divisor);
        long quotient = 0, sum = 0;
        while (sum + absdivisor <= absdividend) {
            sum += absdivisor;
            quotient++;
        }
        if (quotient > INT_MAX && isPositive)
            return INT_MAX;
        if (quotient > INT_MAX && !isPositive)
            return INT_MIN;
        return isPositive ? quotient : -quotient;
        */
        // BIT MANIPULATION
        if (dividend == divisor)
            return 1;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (divisor == 1)
            return dividend;
        bool isPositive = true;
        if (dividend >= 0 && divisor < 0)
            isPositive = false;
        else if (dividend < 0 && divisor > 0)
            isPositive = false;
        long absdividend = abs((long)dividend);
        long absdivisor = abs((long)divisor);
        int quotient = 0;
        while (absdividend >= absdivisor) {
            int cnt = 0;
            while (absdividend >= (absdivisor << (cnt + 1)))
                cnt++;
            absdividend -= (absdivisor << cnt);
            quotient += (1 << cnt);
        }
        if (quotient > INT_MAX && isPositive)
            return INT_MAX;
        if (quotient > INT_MAX && !isPositive)
            return INT_MIN;
        return isPositive ? quotient : -quotient;
    }
};