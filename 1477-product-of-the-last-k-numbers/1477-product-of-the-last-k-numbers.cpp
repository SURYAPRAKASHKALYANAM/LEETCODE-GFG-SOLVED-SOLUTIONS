class ProductOfNumbers {
public:
    vector<int> q;
    int prod = 1;
    ProductOfNumbers() {}

    void add(int num) {
        // BRUTE
        //  q.push_back(num);
        // Optimal
        if (num == 0) {
            q.clear();
            prod = 1;
        } else
            q.push_back(prod *= num);
    }

    int getProduct(int k) {
        // Brute
        // return accumulate(q.end() - k, q.end(), 1, multiplies<int>());
        // Optimal
        if (q.size() < k)
            return 0;
        else if (q.size() == k)
            return prod;
        else
            return prod / q[q.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */