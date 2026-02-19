class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int height;
    MedianFinder() { height = 0; }

    void addNum(int num) {
        height++;
        if (max_heap.empty())
            max_heap.push(num);
        else if (max_heap.top() < num) {
            min_heap.push(num);
        } else
            max_heap.push(num);

        while (min_heap.size() > max_heap.size() ||
               abs((int)max_heap.size() - (int)min_heap.size()) > 1) {
            if (max_heap.size() > min_heap.size()) {
                min_heap.push(max_heap.top());
                max_heap.pop();
            } else {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
    }

    double findMedian() {
        int val1 = max_heap.empty() ? 0 : max_heap.top();
        if (height & 1)
            return val1;
        int val2 = min_heap.empty() ? 0 : min_heap.top();
        return (val1 + val2) / 2.0000;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */