class Solution
{
    public:
    int row_limit, col_limit;
    void goL(int &rStart, int &cStart, vector<vector < int>> &ans, int &elements, int present)
    {
        int end = cStart + present;
        for (; cStart <= end; cStart++)
        {
            if (rStart >= 0 && rStart < row_limit && cStart < col_limit && cStart >= 0)
            {
                ans.push_back({ rStart,
                    cStart });
                elements--;
            }
        }
        end = rStart + present;
        for (; rStart <= end; rStart++)
        {
            if (rStart >= 0 && rStart < row_limit && cStart < col_limit && cStart >= 0)
            {
                ans.push_back({ rStart,
                    cStart });
                elements--;
            }
        }
    }
    void goRL(int &rStart, int &cStart, vector<vector < int>> &ans, int &elements, int present)
    {
        int end = cStart - present;
        for (; cStart >= end; cStart--)
        {
            if (rStart >= 0 && rStart < row_limit && cStart < col_limit && cStart >= 0)
            {
                ans.push_back({ rStart,
                    cStart });
                elements--;
            }
        }
        end = rStart - present;
        for (; rStart >= end; rStart--)
        {
            if (rStart >= 0 && rStart < row_limit && cStart < col_limit && cStart >= 0)
            {
                ans.push_back({ rStart,
                    cStart });
                elements--;
            }
        }
    }
    vector<vector < int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        vector<vector < int>> ans;
        int present = 0;
        int elements = rows * cols;
        row_limit = rows, col_limit = cols;
        while (elements > 0)
        {
            goL(rStart, cStart, ans, elements, present++);
            goRL(rStart, cStart, ans, elements, present++);
        }
        return ans;
    }
};