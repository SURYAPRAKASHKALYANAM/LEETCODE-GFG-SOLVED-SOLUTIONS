class Solution {
public:
    bool check(vector<int>& freq)
    {
        for(auto i:freq) if(i) return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq(26,0),ans;
        for(auto i:p) freq[i-'a']++;
        int len=p.size();
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]-'a']--;
            if(i-len>=0) freq[s[i-len]-'a']++;
            if(check(freq)) ans.emplace_back((i-len+1));
        }
        return ans;
    }
};