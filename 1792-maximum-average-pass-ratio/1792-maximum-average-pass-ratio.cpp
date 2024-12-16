class Solution
{
    public:
        double maxAverageRatio(vector<vector < int>> &classes, int extraStudents)
        {
            priority_queue<pair<double, pair<int, int>>> q;
            auto profit =[& ](double pass, double total)
            {
                return (pass + 1) / (total + 1) - pass / total;
            };
            double ans = 0;
            for (auto i: classes)
            {
                ans += (double) i[0] /  i[1];
                q.push({ profit(i[0], i[1]),{i[0],i[1]} });
            }
            while (extraStudents)
            {
                auto i = q.top();
                q.pop();
                ans += i.first;
                double e1 = i.second.first + 1, e2 = i.second.second + 1;
                q.push({ profit(e1, e2),{e1,e2} });
                extraStudents--;
            }
            return ans /classes.size();
        }
};