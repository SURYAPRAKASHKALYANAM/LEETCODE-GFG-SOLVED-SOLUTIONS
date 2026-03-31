class Solution {
public:
    static inline void rtrim(std::string& s) {
        s.erase(std::find_if(s.rbegin(), s.rend(),
                             std::not1(std::ptr_fun<int, int>(std::isspace)))
                    .base(),
                s.end()); // RIGHTTRIM
    }
    string decodeCiphertext(string encodedText, int rows) {
        int cols = encodedText.size() / rows, k = 0;
        vector<vector<char>> m(rows, vector<char>(cols));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                m[i][j] = encodedText[k++];
            }
        }
        string final_ans = "";
        for (auto i = 0; i < cols; i++) {
            string sub = "";
            int r = 0, c = i;
            while (r < rows && c < cols) {
                sub += m[r][c];
                r++;
                c++;
            }
            final_ans += sub;
        }
        rtrim(final_ans);
        return final_ans;
    }
};