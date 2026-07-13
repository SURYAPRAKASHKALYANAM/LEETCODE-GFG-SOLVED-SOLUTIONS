class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s = "123456789";
        int lowLen = log10(low) + 1;
        int highLen = log10(high) + 1;
        for (int i = lowLen; i <= highLen; i++) {
            int mul = pow(10, i - 1);
            int wLen = i, start = 0;
            int num = 0;
            while (start < wLen) {
                num = num * 10 + (s[start++] - '0');
            }
            if (num >= low && num <= high)
                ans.push_back(num);
            while (start < 9) {
                num -= ((s[start - wLen] - '0') * mul);
                num = num * 10 + (s[start++] - '0');
                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }
        return ans;
    }
};