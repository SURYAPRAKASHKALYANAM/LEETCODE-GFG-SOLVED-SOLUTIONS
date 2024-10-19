class Solution {
public:
    string reversee(string s)
    {
        for(auto &i:s) i=(i=='1')?'0':'1';
        reverse(s.begin(),s.end());
        return s;
    }
    char findKthBit(int n, int k) {
        string s="0";
        while(n--)
        {
            s+="1"+reversee(s);
        }
        return s[k-1];
    }
};