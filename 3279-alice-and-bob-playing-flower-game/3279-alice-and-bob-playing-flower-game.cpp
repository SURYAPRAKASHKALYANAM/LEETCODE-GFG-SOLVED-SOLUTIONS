class Solution {
public:
    long long flowerGame(int n, int m) {
#define ll long long
        ll nOdd = (ll)(n / 2) + (n % 2);
        ll nEve = (ll)(n / 2);
        ll mOdd = (ll)(m / 2) + (m % 2);
        ll mEve = (ll)(m / 2);

        return (nOdd * mEve) + (mOdd * nEve);
    }
};