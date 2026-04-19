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
        int maxVal = 0;
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) {
                maxVal |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxVal;
    }
};
class Solution {
   public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        // your code goes here
        sort(nums.begin(), nums.end());
        vector<pair<pair<int, int>, int>> offqueries;
        int index = 0;
        for (auto query : queries) {
            offqueries.push_back({{query[1], query[0]}, index++});
        }
        sort(offqueries.begin(), offqueries.end());
        vector<int> ans(index, -1);
        int numsIdx = 0;
        Trie* trie = new Trie();
        for (int i = 0; i < index; i++) {
            auto [query, actualIdx] = offqueries[i];
            auto [m, x] = query;
            while (numsIdx < nums.size() && nums[numsIdx] <= m) {
                trie->addNum(nums[numsIdx++]);
            }
            ans[actualIdx] = numsIdx == 0 ? -1 : trie->getMax(x);
        }
        return ans;
    }
};