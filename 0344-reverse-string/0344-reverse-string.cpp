class Solution {
public:
    void reverseString(vector<char>& s) {
       // reverse(s.begin(),s.end());
        char ch;
        int n=s.size();
        for (int i=0;i<n/2;i++)
        {
            ch=s[i];
            s[i]=s[n-1-i];
            s[n-i-1]=ch;
        }
        
    }
};