class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> m;
        set<char> si;
        for(int i=0;i<s.size();i++)
        {
            char a=s[i];
            char b=t[i];
            if(m.find(a)!=m.end())
            {
               if(m[a]!=b)
                {
                    return false;
                 }
            }
            else
            {
                if(si.find(b)!=si.end())
                {
                    return false;
                }
                m[a]=b;
                si.insert(b);
            }
        }
        return true;
    }
};