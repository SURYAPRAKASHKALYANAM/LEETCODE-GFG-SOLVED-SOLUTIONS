class Solution
{
    public:
       	// recursive is not otimal solution it takes more time
       	// int find(int i,int j,int m,int n)
       	// {
       	//     if(i>=m && j!=n-1) return 0;
       	//     if(j>=n && i!=m-1) return 0;
       	//     if(i==m-1 && j==n-1) return 1;
       	//     return find(i+1,j,m,n)+find(i,j+1,m,n);
       	// }
        int uniquePaths(int m, int n)
        {
           	//  use combinatrics
            double res = 1;
            int d = m + n - 2;
            int r = m - 1;
            for (int i = 1; i <= r; i++)
            {
                res = res *(d - r + i) / i;
            }
            return (int) res;
        }
};