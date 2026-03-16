class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> sums;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sums.push_back(grid[i][j]);
                for (int k = 2; (j + (2 * k) - 1) <= n; k++) {
                    //cout<<k<<" "<<i<<" "<<j<<endl;
                    int sum = 0;
                    int r = i, c = j;
                    int steps = k-1;
                    // go to top
                    while (steps>0 && (r<m && r>=0 && c<n && c>=0)){
                        sum+=grid[r][c];
                        //cout<<r<<" "<<c<<endl;
                        r--;c++;
                        steps--;
                    }
                    if(steps!=0) continue;
                    steps=k-1;
                    // go to down
                    while (steps>0 && (r<m && r>=0 && c<n && c>=0)){
                        sum+=grid[r][c];
                        //cout<<r<<" "<<c<<endl;
                        r++;c++;
                        steps--;
                    }
                    if(steps!=0) continue;
                    steps=k-1;

                    // go to back dow
                    while (steps>0 && (r<m && r>=0 && c<n && c>=0)){
                        sum+=grid[r][c];
                        //cout<<r<<" "<<c<<endl;
                        r++;c--;
                        steps--;
                    }
                    if(steps!=0) continue;
                    steps=k-1;

                    // go to start

                    while (steps>0 && (r<m && r>=0 && c<n && c>=0)){
                        sum+=grid[r][c];
                        //cout<<r<<" "<<c<<endl;
                        r--;c--;
                        steps--;
                    }
                    if(steps!=0) continue;
                    sums.push_back(sum);
                }
            }
        }
        sort(sums.rbegin(),sums.rend());
        vector<int> ans;
        ans.emplace_back(sums[0]);
        for(int i=1;i<sums.size();i++){
            if(ans.size()==3) break;
            if(ans.back()!=sums[i]) ans.emplace_back(sums[i]);
        }
        return ans;
    }
};