class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int len = encodedText.size(), cols = len / rows, k = 0;
        string final_ans = "";
        for (int c = 0; c < cols; c++) {
            for (int r = 0; r < rows; r++) {
                int idx = r * cols + c + r;
                if (idx < len)
                    final_ans += (encodedText[idx]);
            }
        }
        while (final_ans.size() && final_ans.back() == ' ')
            final_ans.pop_back();
        return final_ans;
    }
};