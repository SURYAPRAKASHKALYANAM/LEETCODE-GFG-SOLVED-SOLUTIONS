class Solution
{
    public:
        int minOperations(vector<string> &logs)
        {
           	// stack<string> s;
            int t = 0;
            for (int i = 0; i < logs.size(); i++)
            {
                if (logs[i] == "../")
                {
                    if (t == 0) continue;
                    else t--;
                }
                else if (logs[i] != "./") t++;
            }
            return t;
        }
};