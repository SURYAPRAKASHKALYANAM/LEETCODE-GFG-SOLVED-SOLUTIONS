class MinStack {
public:
    stack<long long> st;
    long mini = LONG_MIN;
    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            mini = val;
            st.push(val);
            return;
        }
        if (val > mini) {
            st.push(val);
            return;
        }
        st.push(2L * val - mini);
        mini = val;
    }

    void pop() {
        long x = st.top();
        st.pop();
        if (mini > x) {
            mini = 2L * mini - x;
        }
    }

    int top() {
        long x = st.top();
        if (mini < x)
            return x;
        return mini;
    }

    int getMin() { return mini; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */