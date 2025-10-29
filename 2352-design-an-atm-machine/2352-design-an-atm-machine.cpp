class ATM {
public:
    vector<int> denominations = {20, 50, 100, 200, 500};
    vector<long long> balance;
    ATM() { balance.resize(5, 0); }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++)
            balance[i] = (long long) (balance[i]+banknotesCount[i]);
    }

    vector<int> withdraw(int amount) {
        vector<int> notes(5, 0);
        vector<long long> balanceDummy(balance.begin(), balance.end());
        for (int i = 4; i >= 0; i--) {
            if (balance[i] > 0 && denominations[i] <= amount) {
                long long avail = balance[i];
                long long possible = (long long)amount / (long long)denominations[i];
                long long withdraw = min(avail, possible);
                balance[i] -= withdraw;
                amount -= ((long long)withdraw * (long long)denominations[i]);
                notes[i] = withdraw;
            }
        }
        if (amount != 0)
            balanceDummy.swap(balance);
        return (amount != 0) ? vector<int>(1, -1) : notes;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */