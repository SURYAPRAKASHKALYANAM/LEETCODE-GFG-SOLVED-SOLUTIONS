class StockSpanner
{
    public:
        stack<int> ms, s;
    vector<int> v;
    StockSpanner() {}

    int next(int price)
    {
       	// int k=0;
       	// while(!ms.empty() && ms.top()<=price)
       	// {
       	//     s.push(ms.top());
       	//     ms.pop(); 
       	//     k++;
       	// }
       	// int ans=k+1;
       	// while(!s.empty())
       	// {
       	//     ms.push(s.top());
       	//     s.pop();
       	// }
       	// ms.push(price);

        int ans = 0;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (v[i] > price) break;
            ans++;
        }
        v.emplace_back(price);
        return ans + 1;;
    }
};

/**
 *Your StockSpanner object will be instantiated and called as such:
 *StockSpanner* obj = new StockSpanner();
 *int param_1 = obj->next(price);
 */