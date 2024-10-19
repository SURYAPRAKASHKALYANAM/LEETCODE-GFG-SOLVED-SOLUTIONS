class Solution
{
    public:
    // Brute force
    // string reversee(string s)
    // {
    //     for(auto &i:s) i=(i=='1')?'0':'1';
    //     reverse(s.begin(),s.end());
    //     return s;
    // }
    //=============================================================
    // recursion
    string reversee(string s)
    {
        for (auto &i: s) i = (i == '1') ? '0' : '1';
        reverse(s.begin(), s.end());
        return s;
    }
    string find(int n, int curr, string s)
    {
        if (curr == n) return s;
        s += "1" + reversee(s);
        return find(n, curr + 1, s);
    }
    char findKthBit(int n, int k)
    {
        string s = "0";
       	//Brute force
       	// while(n--)  s+="1"+reversee(s);
        s = find(n, 0, s);
        return s[k - 1];
    }
};