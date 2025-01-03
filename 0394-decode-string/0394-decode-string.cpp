class Solution {
public:
    void repeatString(int rep, string& sub) {
        string s = "";
        while (rep--)
            s += sub;
        sub = s;
    }
    string decodeString(string s) {
        unordered_map<string, int> m;
        for (int i = 0; i < 10; i++)
            m[to_string(i)] = i;
        stack<string> st;
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ']') {
                string sub = "";
                while (!st.empty() && st.top() != "[") {
                    sub = st.top() + sub;
                    st.pop();
                }
                st.pop();
                string num="";
                while (!st.empty() && m.find(st.top())!=m.end()) {
                    num=st.top()+num;
                    st.pop();
                }
                int rep=stoi(num);
                repeatString(rep, sub);
                st.push(sub);
            } else
            {
                string str=string(1,s[i]);
                st.push(str);
            }
        }
        while (!st.empty()) {
            ans = st.top() + ans, st.pop();
        }
        return ans;
    }
};