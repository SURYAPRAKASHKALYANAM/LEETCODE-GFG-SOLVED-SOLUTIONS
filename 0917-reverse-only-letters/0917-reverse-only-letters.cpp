class Solution {
public:
    string reverseOnlyLetters(string s) 
    {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(('a'<=s[i] && s[i]<='z')||('A'<=s[i] && s[i]<='Z'))
            {
                while(!(('a'<=s[j] && s[j]<='z')||('A'<=s[j] && s[j]<='Z')) && j>i) j--;
                swap(s[i],s[j]);
                j--;
            }
            i++;
        }
        return s;
    }
};