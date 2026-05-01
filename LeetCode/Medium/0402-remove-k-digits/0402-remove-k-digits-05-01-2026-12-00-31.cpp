class Solution {
   public:
    string removeKdigits(string nums, int k) {
        // TC : O(2*N), SC : O(N)
        string newNum = "";
        for (char ch : nums) {
            while (k > 0 && !newNum.empty() && newNum.back() > ch) {
                newNum.pop_back();
                k--;
            }
            if (ch == '0' && newNum.empty()) continue;
            newNum.push_back(ch);
        }
        while (k > 0 && !newNum.empty()) {
            newNum.pop_back();
            k--;
        }
        return newNum.empty() ? "0" : newNum;
    }
};