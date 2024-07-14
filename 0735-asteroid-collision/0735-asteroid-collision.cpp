class Solution
{
    public:
        vector<int> asteroidCollision(vector<int> &asteroids)
        {
            vector<int> st;
            for (auto i: asteroids)
            {
                if (i > 0)
                {
                    st.push_back(i);
                    continue;
                }
                if (!st.empty() && st.back() < 0)
                {
                    st.push_back(i);
                    continue;
                }
                else
                {
                    st.push_back(i);
                    int pos = st.size() - 1;
                    while ((pos - 1) >= 0 && st[pos]<0 && st[pos - 1]>0)
                    {
                        if (abs(st[pos]) < abs(st[pos - 1]))
                        {
                            st.pop_back();
                            pos--;
                        }
                        else if (abs(st[pos]) > abs(st[pos - 1]))
                        {
                            st[pos - 1] = st[pos];
                            pos--;
                            st.pop_back();
                        }
                        else pos -= 2, st.pop_back(), st.pop_back();
                    }
                }
            }
            return st;
        }
};