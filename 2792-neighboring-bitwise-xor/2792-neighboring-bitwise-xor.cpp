class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        return accumulate(begin(derived), end(derived), 1, bit_xor<>());
    }
};