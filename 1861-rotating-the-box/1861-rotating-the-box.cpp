class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size(),n=box[0].size();
        vector<vector<char>> ans(n,vector<char> (m,'.'));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) ans[i][j]=box[m-1-j][i];
        }
        for(int i=0;i<m;i++)
        {
            int end=n-1,start=end;
            while(start>=0)
            {
                if(ans[start][i]=='*') end=start;
                else if(ans[start][i]=='#')
                {
                    while(end>=0 && (ans[end][i]=='#' || ans[end][i]=='*')) end--;
                    if(end>=0 && end>start) ans[start][i]='.',ans[end][i]='#';
                }
                start--;
            }
        }
        return ans;
    }
};
// OPTIMAL SOLUTION
// vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
//     int m = box.size(), n = box[0].size();
//     vector<vector<char>> res(n, vector<char>(m, '.'));
//     for (int i = 0; i < m; ++i)
//         for (int j = n - 1, k = n - 1; j >= 0; --j)
//             if (box[i][j] != '.') {
//                 k = box[i][j] == '*' ? j : k;
//                 res[k--][m - i - 1] = box[i][j];
//             }

//     return res;
// }