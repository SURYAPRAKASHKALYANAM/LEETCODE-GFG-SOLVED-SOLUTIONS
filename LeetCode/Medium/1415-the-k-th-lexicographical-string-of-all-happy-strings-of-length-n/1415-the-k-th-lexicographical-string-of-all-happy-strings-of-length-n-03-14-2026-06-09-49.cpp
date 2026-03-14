class Solution {
public:
    string getHappyString(int n, int k) {
        int cnt = 0;
        string ans = "";
        auto dfs = [&](this auto&& dfs, int prev, int curr, string tmp) {
            prev = curr;
            tmp += ('a' + curr);
            if (tmp.size() == n) {
                cnt++;
                if (cnt == k)
                    ans = tmp;
                return;
            }
            for (int i = 0; i < 3; i++) {
                if (cnt == k)
                    break;
                if (prev != i)
                    dfs(prev, i, tmp);
            }
        };
        for (int i = 0; i < 3; i++) {
            if (cnt == k)
                break;
            dfs(-1, i, "");
        }
        return ans;
    }
};