class Node {
public:
    Node* link[10] = {nullptr};
    Node* get(int num) { return link[num]; }
    void add(int num) { link[num] = new Node(); }
};

class Trie {
public:
    Node* root;
    Trie() { root = new Node(); }
    void addNum(int num) {
        Node* node = root;
        int divisor = pow(10, (int)log10(num));
        while (divisor) {
            int curr = num / divisor;
            if (node->get(curr) == nullptr) {
                node->add(curr);
            }
            node = node->get(curr);
            num = num % divisor;
            divisor /= 10;
        }
    }

    int maxPrefix(int num) {
        Node* node = root;
        int divisor = pow(10, (int)log10(num));
        int pref = 0;
        while (divisor) {
            int curr = num / divisor;
            if (node->get(curr) == nullptr) {
                break;
            }
            node = node->get(curr);
            pref++;
            num = num % divisor;
            divisor /= 10;
        }
        return pref;
    }
};

class Solution {
public:
    int trieSol(vector<int>& arr1, vector<int>& arr2) {
        int max_pref = 0;
        Trie* obj = new Trie();
        for (int& i : arr1) {
            obj->addNum(i);
        }

        for (int& i : arr2) {
            max_pref = max(max_pref, obj->maxPrefix(i));
        }
        return max_pref;
    }
    int mapSol(vector<int>& arr1, vector<int>& arr2) {
        int max_num = 0;
        unordered_set<int> st;
        for (auto i : arr1) {
            while (i) {
                st.insert(i);
                i /= 10;
            }
        }
        for (auto i : arr2) {
            while (i) {
                if (st.count(i)) {
                    max_num = max(i, max_num);
                    break;
                }
                i /= 10;
            }
        }
        return max_num == 0 ? 0 : to_string(max_num).size();
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        return trieSol(arr1, arr2);
        return mapSol(arr1, arr2);
    }
};