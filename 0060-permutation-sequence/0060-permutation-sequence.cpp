class Solution {
   public:
    string getPermutation(int n, int k) {
        // Your code goes here
        int factorial = 1;
        string seq = "";
        k--;
        for (int i = 1; i < n; i++) {
            factorial *= i;
            seq += to_string(i);
        }
        seq += to_string(n);
        string result = "";
        while (true) {
            int idx = k / factorial;
            result += seq[idx];
            seq.erase(seq.begin() + idx);
            if (seq.empty()) break;

            k = k % factorial;

            factorial /= seq.size();
        }

        return result;
    }
};