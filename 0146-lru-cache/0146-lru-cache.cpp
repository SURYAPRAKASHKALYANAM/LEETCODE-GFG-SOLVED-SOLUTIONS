class Doubly {
public:
    int key, value;
    Doubly *prev, *next;
    Doubly(int _key, int _value, Doubly* _prev = nullptr,
           Doubly* _next = nullptr) {
        key = _key;
        value = _value;
        prev = _prev;
        next = _next;
    }
};
class LRUCache {
public:
    int maxLen, currLen;
    Doubly *first, *last;
    unordered_map<int, Doubly*> nodeMap;
    LRUCache(int capacity) {
        maxLen = capacity;
        currLen = 0;
        first = new Doubly(-1, -1);
        first->next = last = new Doubly(-1, -1, first);
    }

    int get(int key) {
        if (nodeMap[key] != nullptr) {
            insertBegin(key);
            return nodeMap[key]->value;
        }
        return -1;
    }

    void insertBegin(int& key) {
        Doubly* node = nodeMap[key];
        // if (node->next)
            node->next->prev = node->prev;
        // if (node->prev)
            node->prev->next = node->next;
        node->next = first->next;
        first->next->prev = node;
        first->next = node;
        node->prev = first;
    }

    void DeleteEnd() {
        Doubly* node = last->prev;
        nodeMap[node->key] = nullptr;
        last->prev = node->prev;
        node->prev->next = node->next;
        if (node != first)
            delete node;
    }

    void put(int key, int value) {
        if (nodeMap[key]) {
            nodeMap[key]->value = value;
            insertBegin(key);
        } else {
            if (currLen == maxLen) {
                DeleteEnd();
                currLen--;
            }
            currLen++;
            nodeMap[key] = new Doubly(key, value, first, first->next);
            first->next->prev = nodeMap[key];
            first->next = nodeMap[key];
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */