class MedianFinder {
    double mid1, mid2;
    int totalLen;

public:
    MedianFinder() {
        this->mid1 = INT_MIN;
        this->mid2 = INT_MIN;
        this->totalLen = 0;
    }

    void addNum(int num) {
        if(this->mid1 == INT_MIN) this->mid1=num;
        else if(this->mid2 == INT_MIN) this->mid2=num;
        else if (num > this->mid1 && num <= this->mid2)
            this->mid1 = num;
        else if (this->mid2 > num)
            this->mid2 = num;
        // cout<<this->mid1<<" "<<this->mid2<<endl;
    }
    double findMedian() {
        if (this->totalLen & 1)
            return (double)this->mid;
        return (double)(this->mid1 + this->mid2) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */