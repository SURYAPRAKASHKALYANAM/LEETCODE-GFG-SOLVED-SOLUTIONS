class ATM {
public:
    vector<int> denominations = {20, 50, 100, 200, 500};
    vector<int> balance;
    ATM() { balance.resize(5, 0); }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++)
            balance[i] = (balance[i] + banknotesCount[i]);
    }

    vector<int> withdraw(int amount) {
        vector<int> notes(5, 0);
        for (int i = 4; i >= 0; i--) {
            if (balance[i] > 0 && denominations[i] <= amount) {
                int possible = amount / denominations[i];
                notes[i] = min(balance[i], possible);
                amount -= (notes[i] * denominations[i]);
            }
        }
        if (amount != 0) {
            return {-1};
        }
        for (int i = 0; i < 5; i++)
            balance[i] -= notes[i];
        return notes;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */