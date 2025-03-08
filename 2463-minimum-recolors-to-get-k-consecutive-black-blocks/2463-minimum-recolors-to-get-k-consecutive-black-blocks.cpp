class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int minwhites = INT_MAX, whites = 0;
        for (int i = 0; i < k; i++) {
            whites += (blocks[i] == 'W');
        }
        minwhites = min(minwhites, whites);
        for (int i = k; i < n; i++) {
            if (blocks[i] == 'W') {
                whites++;
            }
            if (blocks[i - k] == 'W')
                whites--;
            minwhites = min(minwhites, whites);
        }
        return minwhites;
    }
};