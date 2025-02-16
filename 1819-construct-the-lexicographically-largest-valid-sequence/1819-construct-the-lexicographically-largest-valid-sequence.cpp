class Solution {
public:
    bool helper(int pos, vector<int>& sequence, vector<int>& placed,
                int seq_len, int ele) {
        while (pos < seq_len && sequence[pos] != 0)
            pos++;
        if (pos == seq_len)
            return true;
        for (int to_place = ele; to_place >= 1; to_place--) {
            if (!placed[to_place]) {
                placed[to_place] = 1;
                if (to_place == 1) {
                    sequence[pos] = to_place;
                    if (helper(pos + 1, sequence, placed, seq_len, ele))
                        return true;
                    sequence[pos] = 0;
                } else if ((pos + to_place) < seq_len &&
                           sequence[pos + to_place] == 0) {
                    sequence[pos] = sequence[pos + to_place] = to_place;
                    if (helper(pos + 1, sequence, placed, seq_len, ele))
                        return true;
                    sequence[pos] = sequence[pos + to_place] = 0;
                }
                placed[to_place] = 0;
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> sequence(2 * n - 1, 0), placed(n + 1, 0);
        helper(0, sequence, placed, 2 * n - 1, n);
        return sequence;
    }
};