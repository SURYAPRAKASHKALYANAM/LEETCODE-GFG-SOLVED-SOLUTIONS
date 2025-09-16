class Solution {
public:
    string removeKdigits(string num, int k) {
        string st = "";
        for (auto i : num) {
            // if (st.empty() && i != '0') {
            //     st.push_back(i);
            // } else {
            while (!st.empty() && st.back() > i && k > 0) {
                k--;
                st.pop_back();
            }
            if (st.empty() && i == '0')
                continue;
            st.push_back(i);
            // }
        }
        while (k && !st.empty()) {
            k--;
            st.pop_back();
        }
        // string s = "";
        // while (!st.empty()) {
        //     s = st.top() + s;
        //     st.pop();
        // }
        return st == "" ? "0" : st;
    }
};