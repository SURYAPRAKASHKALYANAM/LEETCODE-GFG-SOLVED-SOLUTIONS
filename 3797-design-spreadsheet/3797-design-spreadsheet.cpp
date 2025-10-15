class Spreadsheet {
public:
    vector<vector<int>> spreadsheet;
    Spreadsheet(int rows) { spreadsheet.resize(rows + 1, vector<int>(26, 0)); }
    pair<int, int> parse(string& cell) {
        return {stoi(cell.substr(1)), cell[0] - 'A'};
    }
    void setCell(string cell, int value) {
        auto pos = parse(cell);
        spreadsheet[pos.first][pos.second] = value;
    }

    void resetCell(string cell) {
        auto pos = parse(cell);
        spreadsheet[pos.first][pos.second] = 0;
    }

    int valAt(string& cell) {
        auto pos = parse(cell);
        return spreadsheet[pos.first][pos.second];
    }

    int getValue(string formula) {
        string X = "", Y = "";
        bool xEnd = false;
        for (int i = 1; i <= formula.size(); i++) {
            if (formula[i] == '+') {
                xEnd = true;
                continue;
            }
            if (!xEnd)
                X += formula[i];
            else
                Y += formula[i];
        }
        int val1 = 0, val2 = 0;
        if (X[0] >= 'A' && X[0] <= 'Z')
            val1 = valAt(X);
        else
            val1 = stoi(X);
        if (Y[0] >= 'A' && Y[0] <= 'Z')
            val2 = valAt(Y);
        else
            val2 = stoi(Y);
        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */