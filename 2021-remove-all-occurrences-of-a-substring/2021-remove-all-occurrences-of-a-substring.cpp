class Solution {
public:
    string removeOccurrences(string s, string part) {
        int index = s.find(part);
        while (index >= 0) {
            s.erase(index, part.size());
            index = s.find(part);
        }
        return s;
    }
};