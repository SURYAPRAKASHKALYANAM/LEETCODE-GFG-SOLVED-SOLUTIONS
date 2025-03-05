class DoublyLinkedNode {
public:
    pair<int, int> val;
    DoublyLinkedNode *prev, *next;
    DoublyLinkedNode() : val({-1, -1}), prev(nullptr), next(nullptr) {};
    DoublyLinkedNode(pair<int, int> v)
        : val(v), prev(nullptr), next(nullptr) {};
};

class LRUCache {
public:
    int capacity, presentSize = 0;
    DoublyLinkedNode *head, *tail;
    map<int, DoublyLinkedNode*> keyAddress;
    LRUCache(int capacity) {
        this->capacity = capacity;
        presentSize = 0;
        head = new DoublyLinkedNode();
        tail = new DoublyLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(DoublyLinkedNode* node) {
        DoublyLinkedNode* previousNode = node->prev;
        previousNode->next = node->next;
        node->next->prev = previousNode;
    }

    void insertBegin(DoublyLinkedNode* node) {
        DoublyLinkedNode* headNext = head->next;
        headNext->prev = node;
        head->next = node;
        node->prev = head;
        node->next = headNext;
    }

    void deleteEnd() {
        DoublyLinkedNode* last = tail->prev;
        tail->prev = last->prev;
        last->prev->next = tail;
        keyAddress[last->val.first] = nullptr;
    }

    int get(int key) {
        if (keyAddress[key]) {
            deleteNode(keyAddress[key]);
            insertBegin(keyAddress[key]);
            return keyAddress[key]->val.second;
        } else
            return -1;
    }

    void put(int key, int value) {
        if (keyAddress[key]) {
            keyAddress[key]->val.second = value;
            deleteNode(keyAddress[key]);
            insertBegin(keyAddress[key]);

        } else {
            if (presentSize == capacity) {
                deleteEnd();
                presentSize--;
            }
            DoublyLinkedNode* newNode = new DoublyLinkedNode({key, value});
            insertBegin(newNode);
            keyAddress[key] = newNode;
            presentSize++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */