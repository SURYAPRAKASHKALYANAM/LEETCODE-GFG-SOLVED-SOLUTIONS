class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size() - 1;
        int carry = 1;
        while (carry && len >= 0) {
            digits[len] += carry;
            carry = digits[len] / 10;
            digits[len] %= 10;
            len--;
        }
        if (carry)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};