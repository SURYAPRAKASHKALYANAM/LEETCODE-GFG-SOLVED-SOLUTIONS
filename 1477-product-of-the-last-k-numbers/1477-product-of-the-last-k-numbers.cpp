class ProductOfNumbers {
public:
    vector<int> q;
    ProductOfNumbers() {}

    void add(int num) { q.push_back(num); }

    int getProduct(int k) {
        return accumulate(q.end() - k, q.end(), 1, multiplies<int>());
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */