class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int len = points.size();
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            int x = points[i][0], y = points[i][1];
            int samex = 0, samey = 0;
            for (int j = i + 1; j < len; j++) {
                if ((x == points[j][0] && y != points[j][1]))
                    samex = 1;
                else if (x != points[j][0] && y == points[j][1])
                    samey = 1;
                else if (((points[j][0] <= x) && (points[j][1] >= y)) ||
                         ((points[j][0] >= x) && (points[j][1] <= y))) {
                    int lx = min(x, points[j][0]), uy = max(y, points[j][1]);
                    int rx = max(x, points[j][0]), dy = min(y, points[j][1]);
                    bool can = true;
                    for (int k = 0; k < len; k++) {
                        if (k != i && k != j) {
                            int cx = points[k][0], cy = points[k][1];
                            if (cx >= lx && cx <= rx && cy >= dy && cy <= uy) {
                                can = false;
                                break;
                            }
                        }
                    }
                    // if(can){
                    //     cout<<rx<<" "<<dy<<" "<<lx<<" "<<uy<<endl;
                    //     cout<<i<<" "<<j<<endl;
                    // }
                    cnt += can;
                }
            }
            // if(samey){
            //     cout<<i<<" ";
            // }
            cnt += (samex + samey);
        }
        return cnt;
    }
};