class Solution
{
    public:
        vector<double> calcEquation(vector<vector < string>> &equations, vector< double > &values, vector< vector< string>> &queries)
        {
            map<string, vector<pair<string, double>>> adj;
            for (int i = 0; i < values.size(); i++)
            {
                adj[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));
                adj[equations[i][1]].push_back(make_pair(equations[i][0], (double)(1 / values[i])));
            }
            vector<double> ans(queries.size(), -1);
            for (int i = 0; i < queries.size(); i++)
            {
                string src = queries[i][0], end = queries[i][1];
                if(src==end)
                {
                    ans[i]=1;
                    if(!adj[src].size()) ans[i]=-1;
                    continue;
                }
                queue<pair<string, double>> q;
                q.push({src,1});
                map<string, bool> visited;
                bool f1 = 0;
                while (!q.empty())
                {
                    auto it = q.front();
                    q.pop();
                    string curr = it.first;
                    double dis = it.second;
                    if (!visited[curr])
                    {
                        visited[curr] = 1;
                        for (auto next: adj[curr])
                        {

                            string nc = next.first;
                            double w = next.second;
                            if (nc == end) ans[i]=max(ans[i],w*dis);
                            if (!visited[nc]) q.push({ nc, w *dis });
                        }
                    }
                }
            }
            return ans;
        }
};