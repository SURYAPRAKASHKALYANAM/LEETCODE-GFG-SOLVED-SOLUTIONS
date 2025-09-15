class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (int i : asteroids) {
            if (i > 0 || st.empty() || st.back() < 0) {
                st.push_back(i);
            } else {
                while (!st.empty() && st.back() > 0 && st.back() < abs(i))
                    st.pop_back();
                if (!st.empty()) {
                    if (st.back() > 0 && st.back() == abs(i))
                        st.pop_back();
                    else if (st.back() < 0)
                        st.push_back(i);
                } else
                    st.push_back(i);
            }
        }
        return st;
    }
};