class Solution {
public:
    bool casee(int i,int j,string s)
    {
        int n=s.size();
        while(i<n/2 || j>n/2)
        {
            if(s[i]!=s[j]) return false ;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) 
    {
        int n=s.size();
        int i=0,j=n-1,ex=1;
        while(i<n/2 && j>n/2)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
                // cout<<i<<j<<"\n";
                if(ex)
                {
                    if(s[i]==s[j-1] || s[i+1]==s[j]) return casee(i,j-1,s) || casee(i+1,j,s); 
                    else return false;
                    ex--;
                }
                else return false;
            }
        }
        return true;
    }
};