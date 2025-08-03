class Solution {
public:
    string multiply(string num1, string num2) {
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        int carry = 0;
        string res = "";
        vector<string> products;
        string Xs = "";
        int maxlen = 0;
        while (end1 >= 0) {
            string sub = "";
            carry = 0;
            while (end2 >= 0) {
                int mul = (num1[end1] - '0') * (num2[end2] - '0');
                mul += carry;
                if (end2 != 0) {
                    int rem = mul % 10;
                    sub = sub + to_string(rem);
                    carry = mul / 10;
                } else {
                    while (mul) {
                        sub = sub + to_string(mul % 10);
                        mul /= 10;
                    }
                }
                end2--;
            }
            end2 = num2.size() - 1;
            sub = Xs + sub;
            maxlen = max(maxlen, (int)sub.size());
            products.push_back(sub);
            Xs += "X";
            end1--;
        }
        int sum = 0;
        carry = 0;
        for (int i = 0; i < maxlen; i++) {
            sum = carry;
            for (auto sub : products) {
                if (sub.size() > i && sub[i] != 'X') {
                    sum += (sub[i] - '0');
                }
            }
            if (i == (maxlen - 1)) {
                while (sum) {
                    res = to_string(sum % 10) + res;
                    sum /= 10;
                }
            } else {
                res = to_string(sum % 10) + res;
                carry = sum / 10;
            }
        }
        if (count(begin(res), end(res), '0') == res.size() || res.size() == 0)
            return "0";
        return res;
    }
};