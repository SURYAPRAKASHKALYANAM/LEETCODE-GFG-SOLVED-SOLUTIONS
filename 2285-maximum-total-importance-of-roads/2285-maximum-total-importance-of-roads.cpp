class Solution
{
    public:
        long long maximumImportance(int n, vector<vector < int>> &roads)
        {
            long long sum = 0;
            vector<int> indegree(n, 0);
            for (auto i: roads)
            {
                indegree[i[0]]++;
                indegree[i[1]]++;
            }
            sort(indegree.begin(), indegree.end());
            int assign = 1;
            for (auto i: indegree) sum += ((long long)i * (long long)assign++);
            return sum;
        }
};