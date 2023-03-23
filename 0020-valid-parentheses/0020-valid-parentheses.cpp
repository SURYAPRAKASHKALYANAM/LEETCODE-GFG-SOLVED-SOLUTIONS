class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        if(s.size()==1) return false;
        for(auto i:s)
        {
            if(i=='(' || i=='{' || i=='[') st.push(i);
            else
            {
                if(st.empty()) return false;
                if(i==')' && st.top()=='(') st.pop();
                else if(i=='}' && st.top()=='{') st.pop();
                else if(i==']' && st.top()=='[') st.pop();
                else return false;
            }
        }
        return st.empty();
        
    }
};