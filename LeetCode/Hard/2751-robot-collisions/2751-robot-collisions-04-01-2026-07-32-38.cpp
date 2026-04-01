class Solution
{
    public:
        vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
        {
            vector<pair<int, int>> remain;
            vector<pair<int, pair<int, char>>> robots, st;
            map<int, int> m;
            for (int i = 0; i < positions.size(); i++)
            {
                robots.push_back({ positions[i],{ healths[i],directions[i]} });
                m[positions[i]] = i;
            }
            sort(robots.begin(), robots.end());
            for (auto i: robots)
            {
                st.push_back(i);
                int pos=st.size()-1;
                while((pos-1)>=0 && st[pos-1].second.second!=st[pos].second.second)
                {
                    int in=st[pos-1].second.first,out=st[pos].second.first;
                    char d1=st[pos-1].second.second,d2=st[pos].second.second;
                    if(d1=='L' && d2=='R') break;
                    if(d1!=d2)
                    {
                        if(in==out)
                        {
                            pos-=2;
                            st.pop_back();
                            st.pop_back();
                        }
                        else if(in<out)
                        {
                            st[pos-1]=st[pos];
                            st[pos-1].second.first-=1;
                            st.pop_back();
                            pos--;
                        }
                        else
                        {
                            st.pop_back();
                            pos--;
                            st[pos].second.first-=1;
                        }
                    }
                    if(d1==d2) break;
                }    
            }
            for (auto i: st) remain.push_back({ i.first,i.second.first });
            sort(remain.begin(), remain.end(), [& m](pair<int, int> p1, pair<int, int> p2){
                return m[p1.first] < m[p2.first];
            });
            vector<int> ans;
            for (auto i: remain) ans.push_back(i.second);
            return ans;
        }
};