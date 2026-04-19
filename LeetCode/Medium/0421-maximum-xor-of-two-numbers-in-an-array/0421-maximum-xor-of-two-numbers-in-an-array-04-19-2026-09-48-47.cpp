class Node {
    Node* links[2] = {nullptr};

   public:
    bool containsKey(int bit) { return links[bit] != nullptr; }

    void put(int bit) { links[bit] = new Node(); }

    Node* get(int bit) { return links[bit]; }
};

class Trie {
    Node* root;

   public:
    Trie() { root = new Node(); }

    void addNum(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit);
            }
            node = node->get(bit);
        }
    }

    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) {
                maxNum |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution {
   public:
    int findMaximumXOR(vector<int>& nums) {
        // your code goes here
        Trie* obj = new Trie();

        for (int i : nums) obj->addNum(i);

        int maxXor = 0;

        for (int i : nums) {
            maxXor = max(maxXor, obj->getMax(i));
        }

        return maxXor;
    }
};