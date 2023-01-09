class Solution {
public:
    int maxVowels(string s, int k) 
    {
        int c=0,maxi=INT_MIN,j,si=0;
        for(int i=0;i<k;i++)
        {
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                {
                    c++;
                }
        }
        maxi=max(c,maxi);
        for(int i=1;i<=s.size()-k;i++)
        {
            if(s[i+k-1] == 'a' || s[i+k-1] == 'e' || s[i+k-1] == 'i' || s[i+k-1] == 'o' || s[i+k-1] == 'u') c++;    
            if(s[i-1] == 'a' || s[i-1] == 'e' || s[i-1] == 'i' || s[i-1] == 'o' || s[i-1] == 'u') c--;
            maxi=max(c,maxi);
        }
        return maxi;
        
    }
};