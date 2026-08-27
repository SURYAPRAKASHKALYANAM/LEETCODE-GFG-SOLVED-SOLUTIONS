class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int start = 0;
        int ones = 0;
        string ans = "";

        for (int end = 0; end < n; end++) {
            if (s[end] == '1')
                ones++;

            while (ones > k) {
                if (s[start] == '1')
                    ones--;
                start++;
            }

            if (ones == k) {
                while (start <= end && s[start] == '0')
                    start++;

                string curr = s.substr(start, end - start + 1);

                if (ans.empty() ||
                    curr.size() < ans.size() ||
                    (curr.size() == ans.size() && curr < ans)) {
                    ans = curr;
                }
            }
        }

        return ans;
    }
};