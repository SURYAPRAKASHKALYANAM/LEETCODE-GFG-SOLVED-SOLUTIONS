class NumberContainers {
public:
    unordered_map<int, int> container;
    unordered_map<int, set<int>> ele_indexs;
    NumberContainers() {}

    void change(int index, int number) {
        if (container[index] != 0) {
            int prev_number = container[index];
            ele_indexs[prev_number].erase(index);
        }
        container[index] = number;
        ele_indexs[number].insert(index);
    }

    int find(int number) {
        return ele_indexs[number].size() ? *ele_indexs[number].begin() : -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */