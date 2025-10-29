class Bank {
public:
    vector<long long> bal;
    int n;
    Bank(vector<long long>& balance) : bal(balance) { n = balance.size(); }

    bool transfer(int account1, int account2, long long money) {
        if (1 <= account1 && account1 <= n && 1 <= account2 && account2 <= n &&
            money <= bal[account1 - 1]) {
            bal[account1 - 1] -= money;
            bal[account2 - 1] += money;
            return true;
        }
        return false;
    }

    bool deposit(int account, long long money) {
        if (1 <= account && account <= n) {
            bal[account - 1] += money;
            return true;
        }
        return false;
    }

    bool withdraw(int account, long long money) {
        if (1 <= account && account <= n && money <= bal[account - 1]) {
            bal[account - 1] -= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */