class Solution {
public:
    int bestClosingTime(string customers) {
        int len = customers.size();
        int neg = 0;
        int ys = count(customers.begin(), customers.end(), 'Y');
        int min_idx = 0;
        int penalty_min = INT_MAX, curr_pen = 0;
        for (int i = 0; i < len; i++) {
            if ((ys + neg) < penalty_min) {
                min_idx = i;
                penalty_min = (ys + neg);
            }
            if (customers[i] == 'Y')
                ys--;
            else
                neg++;
        }
        if ((ys + neg) < penalty_min) {
            min_idx = len;
            penalty_min = (ys + neg);
        }
        return min_idx;
    }
};