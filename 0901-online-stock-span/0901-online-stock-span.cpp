class StockSpanner
{
    public:
    vector<pair<int,int>> stack;
    vector<int> v;
    StockSpanner() {}

    int next(int price)
    {
        
        //solution 1
        int curr=0;
       while(stack.size() && stack.back().first<=price)
       {
           auto [prevprice,prevspan]=stack.back();
           stack.pop_back();
           curr+=prevspan;
       }
        stack.emplace_back(make_pair(price,curr+1));
        return curr+1;
        //solution 2
        // int ans = 0;
        // for (int i = v.size() - 1; i >= 0; i--)
        // {
        //     if (v[i] > price) break;
        //     ans++;
        // }
        // v.emplace_back(price);
        // return ans + 1;;
    }
};

/**
 *Your StockSpanner object will be instantiated and called as such:
 *StockSpanner* obj = new StockSpanner();
 *int param_1 = obj->next(price);
 */