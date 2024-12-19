class Solution
{
    public:
        vector<int> finalPrices(vector<int> &prices)
        {
            stack<pair<int, int>> st;
            int n = prices.size();
            vector<int> ans(n, 0);
            for (int i = 0; i < n; i++)
            {
               	// cout<<"==============="<<i<<"\n";
                while (!st.empty() && st.top().first >= prices[i])
                {
                    // cout << st.top().first << " " << st.top().second << endl;
                    ans[st.top().second] = st.top().first - prices[i];
                    st.pop();
                }
                st.push({ prices[i],
                    i });
               	// ans[i]=prices[i];
            }
            while (!st.empty())
            {
               	// cout<<st.top().first<<" "<<st.top().second<<endl;
                ans[st.top().second] = st.top().first;
                st.pop();
            }
            return ans;
        }
};