class Solution {
public:
    set<string> uniquecomb;
    void combinations(string str) {
        sort(str.begin(), str.end());
        do {
            uniquecomb.insert(str);
        } while (next_permutation(str.begin(), str.end()));
    }
    void helper(int pos, string curr, int len, string tiles, set<string>& ans) {
        if (pos == len) {
            if (curr.size())
                ans.insert(curr);
            return;
        }
        for (int i = pos; i < tiles.size(); i++) {
            helper(i + 1, curr + tiles[i], len, tiles, ans);
            helper(i + 1, curr, len, tiles, ans);
        }
    }
    int numTilePossibilities(string tiles) {

        set<string> ans;
        int n = tiles.size();
        helper(0, "", n, tiles, ans);
        for (auto i : ans) {
            combinations(i);
        }
        return uniquecomb.size();
    }
};