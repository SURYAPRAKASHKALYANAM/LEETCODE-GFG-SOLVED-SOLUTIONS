class Solution
{
    public:
        void rotate(vector<vector < int>> &matrix)
        {
           	// vector<vector < int>> z;
           	//  int n=matrix.size();
           	//  for(int j=0;j < n;j++)
           	//  {
           	//      vector<int> s;
           	//      for(int i=n-1;i>=0;i--)
           	//      {
           	//          s.emplace_back(matrix[i][j]);
           	//      }
           	//      z.emplace_back(s);
           	//  }
           	//  matrix.swap(z);

           	//optimal 1.transpose 2.reverse each row
            int n = matrix.size();
           	//tarverse upper traingle and swap
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = i + 1; j < n; j++) swap(matrix[i][j], matrix[j][i]);
            }
           	//reverse each row
            for (int i = 0; i < n; i++)
            {
                reverse(matrix[i].begin(), matrix[i].end());
            }
        }
};