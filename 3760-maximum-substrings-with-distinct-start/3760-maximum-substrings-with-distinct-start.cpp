class Solution {
public:
    int maxDistinct(string s) {
        vector<int> seen(26, 0);
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!seen[s[i] - 'a'])
                cnt++;
            seen[s[i] - 'a']++;
        }
        return cnt;
    }
};