class StockSpanner {
public:
    vector<int> arr;
    int n = 0;
    vector<int> pge;
    stack<int> st;
    StockSpanner() { n = 0; }

    int next(int price) {
        n++;
        arr.push_back(price);
        return stockSpan();
    }

    int stockSpan() {
        while (!st.empty() && arr[st.top()] <= arr[n - 1])
            st.pop();
        pge.push_back((st.empty() ? -1 : st.top()));
        st.push(n - 1);
        return n - 1 - pge[n - 1];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */