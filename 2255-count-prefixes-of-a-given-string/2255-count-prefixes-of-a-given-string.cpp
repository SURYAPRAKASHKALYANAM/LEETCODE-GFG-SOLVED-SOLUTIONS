class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt=0;
        for(auto i:words)
        {
            int curr=0;
            while(curr<i.size() && s[curr]==i[curr]) curr++;
            if(curr==i.size()) cnt++;
        }
        return cnt;
    }
};