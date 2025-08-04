class Solution {
public:
    string multiply(string num1, string num2) {
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        int carry = 0, sum = 0;
        string res = "";
        // vector<string> products;
        // string Xs = "";
        int startIdx = 1;
        int maxlen = 0;
        while (end1 >= 0) {
            string sub = "";
            carry = 0;
            while (end2 >= 0) {
                int mul = (num1[end1] - '0') * (num2[end2] - '0');
                mul += carry;
                if (end2 != 0) {
                    sub = to_string(mul%10) + sub;
                    carry = mul / 10;
                } else {
                    if(mul==0) sub=to_string(0) + sub;
                    while (mul) {
                        sub = to_string(mul % 10) + sub;
                        mul /= 10;
                    }
                }
                end2--;
            }
            end2 = num2.size() - 1;
            // cout<<res<<" "<<sub<<endl;
            if (res == "")
                res = sub;
            else {
                sum = 0, carry = 0;
                int idx1 = res.size() - startIdx;
                int idx2 = sub.size() - 1;
                while (idx1 >= 0 && idx2 >= 0) {
                    sum = carry + (res[idx1] - '0') + (sub[idx2] - '0');
                    res[idx1] = '0' + (sum % 10);
                    carry = sum / 10;
                    idx1--;
                    idx2--;
                }
                while (idx2 >= 0) {
                    sum = (sub[idx2] - '0') + carry;
                    res = to_string(sum % 10) + res;
                    carry = sum / 10;
                    idx2--;
                }
                while (carry) {
                    res = to_string(carry % 10) + res;
                    carry = carry / 10;
                }
            }
            startIdx++;
            end1--;
        }
        if (count(begin(res), end(res), '0') == res.size() || res.size() == 0)
            return "0";
        return res;
    }
};