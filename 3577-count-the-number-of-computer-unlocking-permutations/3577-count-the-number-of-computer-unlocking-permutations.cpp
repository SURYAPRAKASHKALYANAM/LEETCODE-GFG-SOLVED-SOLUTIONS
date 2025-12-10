class Solution {
public:
    int mod = 1e9 + 7;
    long long fact(int n) {
        if (n <= 1)
            return 1;
        return ((n % mod * (fact(n - 1) % mod)) % mod);
    }
    int countPermutations(vector<int>& complexity) {
        int len = complexity.size();
        int min_ele = *min_element(complexity.begin(), complexity.end());
        int cnt = count(complexity.begin(), complexity.end(), min_ele);
        if (complexity[0] == min_ele && cnt == 1) {
            return fact(len - 1);
        }
        return 0;
    }
};