class CustomStack
{
    public:
    vector<int> st;
    int len = 0, maxi = 0;
    CustomStack(int maxSize)
    {
        maxi = maxSize;
    }
    void push(int x)
    {
        if (len == maxi) return;
        st.push_back(x);
        len++;
    }

    int pop()
    {
        if (!len) return -1;
        int k = st.back();
        st.pop_back();
        len--;
        return k;
    }

    void increment(int k, int val)
    {
        for (int i = 0; i < k && i < len; i++) st[i] += val;
    }
};

/**
 *Your CustomStack object will be instantiated and called as such:
 *CustomStack* obj = new CustomStack(maxSize);
 *obj->push(x);
 *int param_2 = obj->pop();
 *obj->increment(k,val);
 */