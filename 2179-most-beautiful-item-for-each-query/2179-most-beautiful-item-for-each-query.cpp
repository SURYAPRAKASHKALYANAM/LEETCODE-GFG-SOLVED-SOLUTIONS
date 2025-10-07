class Solution
{
    public:
        vector<int> maximumBeauty(vector<vector < int>> &items, vector< int > &queries)
        {
            sort(items.begin(), items.end());
            unordered_map<int, int> m;
            int maxi = 0;
            for (auto i: items)
            {
                maxi = max(maxi, i[1]);
                m[i[0]] = maxi;
            }
            vector<int> ans(queries.size(), 0);
            for (auto i = 0; i < queries.size(); i++)
            {
                if (!m[queries[i]])
                {
                    if (queries[i] < items[0][0]) continue;
                    int start = 0, end = items.size(), target = queries[i], mid;
                    bool find = 1;
                    while (start < end)
                    {
                        mid = (start + end) / 2;
                        if (mid - 1 >= 0 && (items[mid - 1][0] < target && items[mid][0] > target))
                        {
                            ans[i] = m[items[mid - 1][0]];
                            find = 0;
                            break;
                        }
                        if (mid + 1 < items.size() && (items[mid][0] < target && items[mid + 1][0] > target))
                        {
                            ans[i] = m[items[mid][0]];
                            find = 0;
                            break;
                        }
                        if (items[mid][0] > target) end = mid - 1;
                        else start = mid + 1;
                    }
                    if (find) ans[i] = m[items[mid][0]];
                    continue;
                }
                ans[i] = m[queries[i]];
            }
            return ans;
        }
};
/* OPTIMAL SOLUTION
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        int n = items.size();
        vector<int> maxBeauty(n),prices(n);
        maxBeauty[0] = items[0][1];
        prices[0] = items[0][0];
        for(int i =1;i<n;i++) {
            prices[i] = items[i][0];
            maxBeauty[i] = max(maxBeauty[i-1],items[i][1]);
        }
        int m = queries.size();
        vector<int> ans(m);
        for(int i = 0;i<m;i++) {
            int idx = bs(prices,queries[i]);
            if(idx == -1) {
                ans[i] = 0;
            }
            else {
                ans[i] = maxBeauty[idx];
            }
        }
        return ans;
    }

    int bs(vector<int>& prices,int target) {
        int low = 0;
        int high = prices.size() - 1;
        int result = -1;
        while(low <= high) {
            int mid = low + (high -low) / 2;
            if(prices[mid] <= target) {
                result = mid;
                low = mid +1;
            }
            else {
                high = mid - 1;
            }
        }
        return result;
    }
};*/