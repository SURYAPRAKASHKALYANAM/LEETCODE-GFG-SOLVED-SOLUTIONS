class Cashier
{
    private:
        unordered_map<int,int> price;
        int n, discount, curr = 0;
    public:
        Cashier(int n, int discount, vector<int> &products, vector<int> &prices)
        {
            this->n = n;
            this->discount = discount;
            for (int i = 0; i < products.size(); i++) this->price[products[i]] = prices[i];
        }
    double getBill(vector<int> product, vector<int> amount)
    {
        double total = 0;
        for (int i = 0; i < product.size(); i++)
        {
            total += (this->price[product[i]] *amount[i]);
        }
        this->curr++;
        if(this->curr==this->n)
        {
            total=total*((double)(100-(this->discount))/100);
            this->curr=0;
        }
        return total;
    }
};

/**
 *Your Cashier object will be instantiated and called as such:
 *Cashier* obj = new Cashier(n, discount, products, prices);
 *double param_1 = obj->getBill(product,amount);
 */