class Solution
{
    public:
        double averageWaitingTime(vector<vector < int>> &customers)
        {
            double sum = customers[0][1], time = sum + customers[0][0];
            int n = customers.size();
            for (int i = 1; i < n; i++)
            {
                if (time >= customers[i][0])
                {
                    time += customers[i][1];
                    sum += (time - customers[i][0]);
                }
                else
                {
                    time = customers[i][0] + customers[i][1];
                    sum += customers[i][1];
                }
            }
            return sum / n;
        }
};