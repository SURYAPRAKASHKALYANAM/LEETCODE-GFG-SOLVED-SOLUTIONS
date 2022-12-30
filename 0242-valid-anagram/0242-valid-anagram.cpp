class Solution {
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char,int> mc;
        for(int i=0;i<s.size();i++) mc[s[i]]++;
        for(int i=0;i<t.size();i++) mc[t[i]]--;
        for(auto i=mc.begin();i!=mc.end();i++)
        {
            // cout<<(i->first)<<i->second;
            if(i->second!=0) return false;
        }
        return true;
        
    }
};