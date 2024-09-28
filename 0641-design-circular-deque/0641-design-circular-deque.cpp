class MyCircularDeque {
public:
    vector<int> v;
    int len;
    MyCircularDeque(int k) {
        len=k;
    }
    
    bool insertFront(int value) {
        if(v.size()==len) return false;
        v.insert(v.begin(),value);
        return true;
    }
    
    bool insertLast(int value) {
        if(v.size()==len) return false;
        v.emplace_back(value);
        return true;
    }
    
    bool deleteFront() {
        if(v.size()==0) return false;
        v.erase(v.begin());
        return true;
    }
    
    bool deleteLast() {
        if(v.size()==0) return false;
        v.pop_back();
        return true;
        
    }
    
    int getFront() {
        return v.size()?v.front():-1;
    }
    
    int getRear() {
        return v.size()?v.back():-1;
    }
    
    bool isEmpty() {
        return v.size()==0;
    }
    
    bool isFull() {
        return v.size()==len;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */