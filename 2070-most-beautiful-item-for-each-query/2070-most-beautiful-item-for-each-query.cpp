class Solution
{
    public:
        vector<int> maximumBeauty(vector<vector < int>> &items, vector< int > &queries)
        {
            sort(items.begin(), items.end());
            unordered_map<int, int> m;
            int maxi=0;
            for (auto i: items)
            {
                maxi = max(maxi, i[1]);
                m[i[0]]=maxi;
            }
            vector<int> ans(queries.size(), 0);
            for (auto i = 0; i < queries.size(); i++)
            {
                if (!m[queries[i]])
                {
                    if (queries[i] < items[0][0]) continue;
                    int start = 0, end = items.size(), target = queries[i], mid;
                    bool find=1;
                    while (start < end)
                    {
                        mid = (start + end) / 2;
                        if(mid-1>=0 && (items[mid-1][0]<target && items[mid][0]>target))
                        {
                            ans[i] = m[items[mid-1][0]];
                            find=0;
                            break;
                        }
                        if(mid+1<items.size() && (items[mid][0]<target && items[mid+1][0]>target))
                        {
                            ans[i] = m[items[mid][0]];
                            find=0;
                            break;
                        }
                        if (items[mid][0] > target) end = mid-1;
                        else start = mid + 1;
                    }
                    // mid = (start + end) / 2;
                    // cout<<start<<" "<<end<<endl;
                    if(find) ans[i] = m[items[mid][0]];
                    continue;
                }
                ans[i] = m[queries[i]];
            }
            return ans;
        }
};
/*
[[743,617],[773,350],[937,643],[395,585],[126,690],[284,656],[999,401],[239,316],[214,811],[269,539],[693,633],[653,801],[108,465],[383,169],[676,956],[155,329],[872,275],[510,557],[423,169]]
[506,294,743,203,553,1790,588,1550,1007,1946,1263,1544]
[[1,2],[3,2],[2,4],[5,6],[3,5]]
[1,2,3,4,5,6]
[[1,2],[1,2],[1,3],[1,4]]
[1]
[[10,1000]]
[5]
[[1,1],[1,1000000000],[1,1000000000]]
[1000000000]*/