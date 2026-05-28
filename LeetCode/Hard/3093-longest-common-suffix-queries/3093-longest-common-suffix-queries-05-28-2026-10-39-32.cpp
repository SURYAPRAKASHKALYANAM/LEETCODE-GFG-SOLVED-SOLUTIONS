class Node {
public:
    Node* link[26] = {nullptr};
    int idx;
    ~Node() {
        for (int i = 0; i < 26; i++)
            delete link[i];
    }
    void add(char ch, int _idx) {
        link[ch - 'a'] = new Node();
        link[ch - 'a']->idx = _idx;
    }
    Node* get(char ch) { return link[ch - 'a']; }
};

class Trie {
    Node* root;

public:
    Trie() { root = new Node(); }
    ~Trie() { delete root; }
    void addString(const string& s, const int idx) {
        Node* node = root;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (node->get(s[i]) == nullptr)
                node->add(s[i], idx);
            node = node->get(s[i]);
        }
    }

    int maxSuff(const string& s) {
        int ans = -1;
        Node* node = root;
        for (int i = s.size() - 1; i >= 0; i--) {
            Node* curr = node->get(s[i]);
            if (!curr)
                break;
            ans = curr->idx;
            node = curr;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {
        int len = wordsContainer.size();
        vector<int> sortedIndices(len);
        iota(sortedIndices.begin(), sortedIndices.end(), 0);

        sort(sortedIndices.begin(), sortedIndices.end(), [&](int a, int b) {
            if (wordsContainer[a].size() != wordsContainer[b].size()) {
                return wordsContainer[a].size() < wordsContainer[b].size();
            }
            return a < b;
        });
        Trie* obj = new Trie();
        for (int& i : sortedIndices) {
            obj->addString(wordsContainer[i], i);
        }
        int qLen = wordsQuery.size();
        vector<int> ans;
        ans.reserve(qLen);
        int smallest = sortedIndices[0];
        for (int i = 0; i < qLen; i++) {
            int idx = obj->maxSuff(wordsQuery[i]);
            ans.emplace_back((idx == -1 ? smallest : idx));
        }
        delete obj;
        return ans;
    }
};